#include <algorithm>
#include <fstream>
#include <utility>
#include <deque>

int n;
struct sub {
    unsigned long long len;
    unsigned char ch;

    sub(unsigned long long _len, unsigned char _ch) :
            len(_len), ch(_ch) {}
};

unsigned long long ans;
std::deque<sub> s;

int main(int argc, const char** argv) {
    std::ifstream fin("string.in");
    std::ofstream fout("string.out");
    if (!fin || !fout) return 0;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        unsigned long long a;
        unsigned char c;
        fin >> a >> c;

        if (!s.empty() && c == s.back().ch) {
            s.back().len += a;
        }
        else {
            s.emplace_back(
                a,
                c
            );
        }
    }

    while (s.size() > 1) {
        sub& a = s.front();
        sub& b = s.back();

        if (a.ch != b.ch) ans += std::min(a.len, b.len);

        a.len -= std::min(a.len, b.len);
        b.len -= std::min(a.len, b.len);

        if (a.len <= 0) {
            s.pop_front();
        }
        if (b.len <= 0) {
            s.pop_back();
        }
    }

    fout << ans << "\n";

    fout.flush();
    return 0;
}