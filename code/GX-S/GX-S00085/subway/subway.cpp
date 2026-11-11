#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=507,INF=1e17+7;
ll c,m,n,d,q,w[N],a[N][N],t[N][N],f[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
                f[i][j]=INF;
    for(int i=1;i<=m;i++)
        f[i][i]=0;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1,p;i<=n;i++){
        cin>>p;
        for(int j=1;j<=p;j++)
            cin>>a[i][j]>>t[i][j];
        for(int j=1;j<=p;j++)
            for(int k=j+1;k<=p;k++){
                f[a[i][j]][a[i][k]]=min(t[i][j]+t[i][k],f[a[i][j]][a[i][k]]);
            }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=m;k++)
                if(i!=j&&i!=k&&j!=k)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        if(x>y)swap(x,y);
        cout<<w[x]+f[x][y]+w[y]<<endl;
    }
    return 0;
}
