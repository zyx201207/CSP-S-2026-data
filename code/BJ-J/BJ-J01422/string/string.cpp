#include <bits/stdc++.h>
using namespace std;
int n, ans, l;
string s, qu;
int main()
{
    freopen("string.in", "w", "in");
    freopen("string.out", "r", "out");
    s=" ";
    cin >> n;
    for (int i=1, a; i<=n; i++)
    {
        cin >> a >> qu, l+=a;
        for (int j=1; j<=a; j++) s+=qu;
    }
    for (int i=1; i<=l/2; i++) if(s[i]!=s[l-i+1]) ans++;
    cout << ans;
}