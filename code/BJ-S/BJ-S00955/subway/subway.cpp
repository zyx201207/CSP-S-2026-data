#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=25;
int c,n,m,d,q,w[N],p[N*25][N*25];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(p,0x3f,sizeof(p));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[m];
    for(int i=1;i<=n;i++){
        int k,a[25],t[25];
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
        for(int j=1;j<=k;j++){
            if(j>=2) p[a[j]*(d+1)+i][a[j-1]*(d+1)+i]=p[a[j-1]*(d+1)+i][a[j]*(d+1)+i]=0;
            p[a[j]*(d+1)][a[j]*(d+1)+i]=p[a[j]*(d+1)+i][a[j]*(d+1)]=t[j];
        }
    }
    for(int k=1;k<(d+2)*n;k++){
        for(int i=1;i<(d+2)*n;i++){
            for(int j=1;j<(d+2)*n;j++){
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+p[x*(d+1)][y*(d+1)]<<"\n";
    }
    return 0;
}