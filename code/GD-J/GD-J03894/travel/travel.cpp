#include <cstdio>
#include <cstring>
#define running_type 'C'
#define pass (void(0))

FILE* fin; FILE* fout;

inline bool func(const char a, const char b) {
    bool al = (a == 'D' || a == 'F'), bl = (b == 'D' || b == 'F');
    return al == bl;
}

struct cs {
public:
    char c[4], s[5];
    cs(void) : c("\0\0\0"), s("\0\0\0\0") { pass; }
    void scan(void) {
        fgets(c+1, 3, fin), fgets(s+1, 5, fin), fgetc(fin);
        s[1] = s[2], s[2] = s[3], s[3] = s[4], s[4] = '\0';
    }
} r, x;

int main(void) {
    #if running_type == 'C'
        fin = fopen("travel.in", "r"), fout = fopen("travel.out", "w");
    #elif running_type == 'T'
        fin = stdin, fout = stdout;
    #endif
    r.scan(); x.scan();
    fputc((r.c[1] == x.c[1] && r.c[2] == x.c[2]) + '0', fout);
    fputc((r.s[1] == x.s[1] && r.s[2] == x.s[2]) + '0', fout);
    fputc(func(r.s[3], x.s[3]) + '0', fout);
    int y = r.s[3] - x.s[3];
    fputc((y == 1 || y == -1) + '0', fout);
    return 0;
} 
