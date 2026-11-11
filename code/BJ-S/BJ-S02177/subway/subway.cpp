#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=5e5+5;
int c[M];
struct node{
    int id,t;
};
vector<node>st[M];
ll dis[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //double t1=clock();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int cc,n,m,d,q;
    cin>>cc>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>c[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int p,t;
            cin>>p>>t;
            st[p].emplace_back(node{i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;++i)dis[i][i]=0;
    for(int i=1;i<=m;++i){
        for(node k1:st[i]){
            for(node k2:st[i]){
                int p1=k1.id,p2=k2.id;
                dis[p1][p2]=min(dis[p1][p2],(ll)k1.t+k2.t);
                dis[p2][p1]=min(dis[p2][p1],(ll)k1.t+k2.t);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(node k1:st[x]){
            for(node k2:st[y]){
                ans=min(ans,k1.t+k2.t+dis[k1.id][k2.id]);
            }
        }
        cout<<ans+c[x]+c[y]<<"\n";
    }
    //double t2=clock();
    //cout<<(t2-t1)/CLOCKS_PER_SEC;
    return 0;
}
//15:21
