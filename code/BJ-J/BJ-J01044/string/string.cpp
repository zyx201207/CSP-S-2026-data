#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> ch;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        char c;
        cin >> a >> c;
        for(int i = 1;i <= a;i++)
            ch.push_back(c);
    }
    int ans = 0;
    for(int i = 0;i < ch.size() / 2;i++)
        if(ch[i] != ch[ch.size()-1 - i]) ans++;
    cout << ans;
    return 0;
}
