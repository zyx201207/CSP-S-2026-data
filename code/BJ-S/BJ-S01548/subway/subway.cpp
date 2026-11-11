#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f;
int c,n,m,d,q;
int fa[500005],e[500005][500005];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j)e[i][j]=0;
            else e[i][j]=INF;
        }
    }
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>e[0][i];
        e[i][0]=e[0][i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++){
            int a,t;
            cin>>a>>t;
            e[i][a]=e[a][i]=t;
        }
    }
    int x=min(m,n);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(e[i][k]!=INF&&e[k][j]!=INF&&e[i][k]+e[k][j]<e[i][j]){
                    e[i][j]=e[i][k]+e[k][j];
                }

            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<e[x][y]<<endl;
    }
    return 0;
}
