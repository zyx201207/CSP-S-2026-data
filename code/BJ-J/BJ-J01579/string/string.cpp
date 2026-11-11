#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N], cnt; char c;
string s = " ";
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> c;
        for(int j=1; j<=a[i]; j++) s += c;
    }
    int m = s.size()-1; int l = m/2, r;
    if(m % 2 == 1) r = m/2+2;
    else r = m/2+1;
    while(l > 0)
    {
        if(s[l] != s[r]) cnt++;
        l--, r++;
    }
    cout << cnt << '\n';
    return 0;
}
