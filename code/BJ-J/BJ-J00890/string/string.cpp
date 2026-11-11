#include<bits/stdc++.h>
using namespace std;

int n,k1,t=1,ans;
char k2;
char s[10000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> k1;
        cin >> k2;
        for(int j = 1;j<=k1;j++)
        {
            s[t] = k2;
            t++;
        }
    }
    for(int i = 1;i<=t/2;i++)
    {
        if(s[i]!=s[t-i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
