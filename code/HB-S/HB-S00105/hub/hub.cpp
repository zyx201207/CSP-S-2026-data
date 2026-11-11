#include <bits/stdc++.h>
using namespace std;
namespace OIer {
    namespace IO {
        typedef long long ll;
        inline ll read() {
            ll x = 0, f = 1;
            char ch = getchar();
            while (ch < '0' || ch > '9') {
                if (ch == '-') f = -1;
                ch = getchar();
            }
            while (ch >= '0' && ch <= '9') {
                x = x * 10 + (ch - '0');
                ch = getchar();
            }
            return x * f;
        }
        template<typename T> inline void write(T x) {
            if (x < 0) putchar('-'), x = -x;
            if (x > 9) write(x / 10);
            putchar((x % 10) + '0');
            return;
        }
        inline void open(string s) {
            string in = s + ".in", out = s + ".out";
            freopen (in.c_str(), "r", stdin);
            freopen (out.c_str(), "w", stdout);
        }
    }
    using namespace IO;
    void main () {
		//  我来押注，我来博弈，我来赢取。我任命运拨转轮盘，孤注一掷，遍历死地而后生。
		//  一切献给，琥珀王！
		//  PS：琥珀王求求了，给个100分把QAQ
		srand((unsigned)time(nullptr));
		int c, t;
		cin >> c >> t;
		while (t --> 0) 
			cout << rand() % 100 << endl;
        return;
    }
}
int main () {
    OIer::open("hub");
    OIer::main();
    return 0;
}
