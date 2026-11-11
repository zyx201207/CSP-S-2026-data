#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q;
int w[M],k,a,t,x,y;
int floyid[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(floyid,0x3f,sizeof(floyid));
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            floyid[a][m+i]=t;
            floyid[m+i][a]=t;
        }
    }
    for(int k=1;k<=m+n;k++){
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                floyid[i][j]=min(floyid[i][j],floyid[i][k]+floyid[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<w[x]+w[y]+floyid[x][y]<<'\n';
    }
    return 0;
}
