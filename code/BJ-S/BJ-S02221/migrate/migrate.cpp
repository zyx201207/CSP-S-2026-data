#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int c,t;ll x[N],d[N][N],f[N][N];
int main()
{
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        int n;ll D;cin>>n>>D;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) d[i][j]=3e18,f[i][j]=0;
        for(int i=1;i<=n;i++) d[i][i]=0,f[i][i]=1;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(x[j]-x[i]<=D) d[i][j]=1,f[i][j]=1;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=i+1;k<j;k++)
        {
            if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j],f[i][j]=f[i][k]*f[k][j];
            else if(d[i][k]+d[k][j]==d[i][j]) f[i][j]+=f[i][k]*f[k][j];
            f[i][j]=min(f[i][j],3ll);
        }
        int ans=0;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            //cout<<i<<" "<<j<<" "<<d[i][j]<<" "<<f[i][j]<<endl;
            ans+=(f[i][j]==2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}