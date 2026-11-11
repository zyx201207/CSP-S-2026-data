#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
    int c, t;
    cin >> c >> t;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i=1;i<=n;i++)
            cin >>a[i];
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {

                int dt=abs(a[j]-a[i]);
                if(dt%k!=0 &&(((dt%2==0)&&(k%2==1)) || ((dt%2==1)&&(k%2==0))))
                {
                    if (dt>2)
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
