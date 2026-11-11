#include<bits/stdc++.h>
const int N=1e3+503;
long long hyw,ccf,n,m,q,d[N][N],plu[N];
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(d,0x3f,sizeof(d));
    cin>>hyw>>n>>m>>ccf>>q;
    for(int i=1;i<=m+n;i++) d[i][i]=0;
    for(int i=1;i<=m;i++) cin>>plu[i];
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        while(t--){
            int x,y;cin>>x>>y;
            d[m+i][x]=d[x][m+i]=y;
        }
    }
    for(int k=1;k<=m+n;k++)
        for(int i=1;i<=m+n;i++)
            for(int j=1;j<=m+n;j++)
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[j][i]=d[i][k]+d[k][j];
    while(q--){
        int x,y;cin>>x>>y;
        cout<<plu[x]+plu[y]+d[x][y]<<"\n";
    }
    return 0;
}
