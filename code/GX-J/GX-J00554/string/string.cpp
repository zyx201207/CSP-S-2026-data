#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s = "";
    int n,a,ans=0;
    char c;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a >> c;
        for (int j = 1;j <= a;j++) s += c;
    }
    for (int i = 0;i <= s.length() / 2 - 1;i++){
        if (s[i] != s[s.length() - 1 - i]) ++ans;
    }
    cout << ans;
    return 0;
}
