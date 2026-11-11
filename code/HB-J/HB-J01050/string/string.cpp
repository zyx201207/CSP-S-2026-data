#include <bits/stdc++.h>
using namespace std;

int n, s=0;
string str, rstr;

void dfs() {
    rstr = str;
    reverse(rstr.begin(), rstr.end());
    if(rstr == str) {
        return;
    } else {
        s=rand()%str.length();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int i, j, a;
    char c;
    cin >> n;
    for(i=1;i<=n;++i) {
        cin >> a >> c;
        for(j=1;j<=a;++j) {
            str = str + c;
        }
    }
    dfs();
    cout << s;
    return 0;
}