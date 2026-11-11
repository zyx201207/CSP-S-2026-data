#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int cnt = 0;
int k = 0;
int ans = 0;
int x;
char c;
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    s = "";
    for(int i = 1; i <= n; i ++)
    {
        cin >> x >> c;
        cout << x << c;
        k += x;
        while(x --)
        {
            s[cnt ++] = c;
        }
    }
    int t = k - 1;
    for(int i = 0; i < k / 2; i ++)
    {
        if(s[i] != s[t]) {ans++; }
        t --;
    }
    cout << ans;
    return 0;
}
