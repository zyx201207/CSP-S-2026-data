#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        int n;
        long long d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+2;j <= n;j++)
            {
                if((a[j]-a[i])/d == 1ll*1 && (a[j]-a[i])%d != 1ll*0)ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
