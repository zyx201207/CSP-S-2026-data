#include <fstream>
#include <string>

struct Ticket {
    int c;  // che1 xiang1
    std::string s_str;  // zuo4 wei4
    struct S {  // for example, 02A
        int s_n;  // 02
        char s_c;  // A
    } s;
};

int ans[5];
Ticket p/*little P*/, x/*little X*/;

bool check(char a, char b, bool power) {
    if (a == 'A' && b == 'B') return true;
    else if (a == 'B' && b == 'C') return true;
    else if (!power && a == 'A' && b == 'C') return true;
    else if (a == 'D' && b == 'F') return true;
    else return false;
}

int main(int argc, const char** argv) {
    std::ifstream fin("travel.in");
    std::ofstream fout("travel.out");
    if (!fin || !fout) return 0;

    fin >> p.c >> p.s_str;
    p.s.s_n = std::stoi(p.s_str.substr(0, 2));
    p.s.s_c = static_cast<char>(p.s_str.back());
    fin >> x.c >> x.s_str;
    x.s.s_n = std::stoi(x.s_str.substr(0, 2));
    x.s.s_c = static_cast<char>(x.s_str.back());

    ans[1] = (p.c == x.c);
    ans[2] = (ans[1] && p.s.s_n == x.s.s_n);
    ans[3] = (ans[2] && (check(p.s.s_c, x.s.s_c, false) || 
                            check(x.s.s_c, p.s.s_c, false)));
    ans[4] = (ans[3] && (check(p.s.s_c, x.s.s_c, true) || 
                            check(x.s.s_c, p.s.s_c, true)));

    for (int i = 1; i <= 4; ++i) {
        fout << ans[i];
    }
    fout << "\n";

    fout.flush();
    return 0;
}