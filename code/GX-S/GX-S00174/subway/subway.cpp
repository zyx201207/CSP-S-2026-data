#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,inf=0x3f3f3f3f;
ll c,n,m,d,q,ma=-1;
ll a[N],t[N],vis[N],f[N][N],x[N],y[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(f,inf,sizeof(f));
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x[j]>>y[j];
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                f[x[j]][x[l]]=f[x[l]][x[j]]=min(f[x[j]][x[l]],y[j]+y[l]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(f[i][k]+f[k][j]<f[i][j])f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,z;
        cin>>s>>z;
        cout<<f[s][z]+a[s]+a[z]<<endl;
    }
    return 0;
}
