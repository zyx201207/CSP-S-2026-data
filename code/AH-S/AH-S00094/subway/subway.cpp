#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
ll c,n,m,d,q;
ll w[maxn],dis[maxn][maxn];
ll num,a[maxn],t[maxn];
bitset<maxn> g[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>num;
        for(int i=1;i<=num;++i){
            cin>>a[i]>>t[i];
        }
        for(int i=1;i<=num;++i){
            for(int j=1;j<=num;++j){
                if(i!=j){
                    dis[a[i]][a[j]]=t[i]+t[j];
                }
            }
        }
    }
    for(int k=1;k<=m;++k){
        for(int i=1;i<=m;++i){
            if(i!=k)
                for(int j=1;j<=m;++j){
                    if((i!=j)&&(j!=k))
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
        }
    }
    /*for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            if(dis[i][j]<0x3f3f3f3f) cout<<dis[i][j]<<' ';
            else cout<<-1<<' ';
        }
        cout<<endl;
    }*/
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
//44