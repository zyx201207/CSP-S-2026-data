#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#define running_type 'C'
using std::cin; using std::cout; using std::string;

using u_int = unsigned int;

int main(void) {
    std::ios::sync_with_stdio(false); cin.tie(0);
    #if running_type == 'C'
        freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
    #endif
    string in;
    u_int i, tmp1;
    char tmp2;
    cin >> i;
    for(int j = i; j > 0; j--) {
        cin >> tmp1 >> tmp2;
        in += string(tmp1, tmp2);
    }
    if(i == 1) {
        cout << '0';
        return 0;
    }
    string t2 = in;
    reverse(t2.begin(), t2.end());
    if(t2 == in) {
        cout << '0';
    } else {
        u_int h_sz = (t2.size() >> 1), ans = 0U;
        for(i = 0U; i < h_sz; ++i) {
            if(in[i] != t2[i]) ++ans;
        }
        cout << ans;
    }
    return 0;
}
