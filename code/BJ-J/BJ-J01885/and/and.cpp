#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int INF=1e9;
int n,m,a[maxn];
long long ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m){
        for(int i=1;i<=n;i++) ans=(ans&a[i]);
        cout<<ans<<'\n';
    }
    else if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,1ll*a[i]);
        cout<<ans<<'\n';
    }
    else {
        for(int i=1;i<=m;i++) ans=(ans&a[i]);
    }
    /*else if(n<=2000){
        int f[2010][2010];
        for(int i=1;i<=n;i++) f[i][0]=-INF;
        for(int j=1;j<=m;j++) f[0][j]=-INF;
        f[1][1]=a[1];
        for(int j=2;j<=m;j++) f[1][j]=-INF;
        for(int i=2;i<=n;i++){
            f[i][1]=max(f[i-1][1],a[i]);
            for(int j=2;j<=m;j++) f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
        }
        cout<<f[n][m]<<endl;
    }*/
    return 0;
}
