#include <SWI-Prolog.h>
#include <stdio.h>

static foreign_t
pl_say_hello(term_t to)
{
    char* a;
    if (PL_get_atom_chars(to, &a)) {
        printf("Hello, %s\n", a);
        PL_succeed;
    } else {
        PL_fail;
    }
}

install_t
install_foo()
{
    PL_register_foreign("say_hello", 1, pl_say_hello, 0);
}
