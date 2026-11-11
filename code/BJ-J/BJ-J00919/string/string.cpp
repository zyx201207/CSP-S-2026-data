#include <bits/stdc++.h>
using namespace std;

//Remember long long;
//freopen() 召唤成功
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;cin >> T;
    while(T --)
    {
        int n; char x;
        cin >> n >> x;
        for(int i = 1; i <= n; i ++)
            s += x;
    }
    int stz = s.size();
    long long ans = 0;
    for(int i = 0; i <= stz / 2; i ++)
    {
         if(s[i] != s[stz - i - 1])ans ++;
    }
    cout << ans;
    return 0;
}
/*
Wake
The fire in the rises,The life alike;
Our life are change, It busy now.
street will go, Forever rises,
Going like me through the night.
...
...
You wake within me,wake within me,
you re in my heart forever.
Forever,Forever,
you in my heart forever
Forever,Forever,

For My Best Friend, WJT
*/
