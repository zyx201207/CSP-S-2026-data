#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000020];
ll y[2000020][2000020];
ll flag1[2000020]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        ll n,d;
        ll ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                y[i][j]=x[j]-x[i];
            for(int j=i;j<n;j++)
            {
                if(y[i][j]<=d)
                {
                    flag1[i]++;
                }
                if(j<=flag1[i])
                {
                    ans+=flag1[j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
