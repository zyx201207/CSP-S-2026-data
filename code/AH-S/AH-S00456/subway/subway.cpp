#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Stu{
    ll color,to;
};
ll c,m,n,d,q;
ll w[500010],t[500010][510],a[500010];
vector<Stu> g[500010];
ll dis[500010];
void bfs(int s){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(t,0x3f,sizeof t);
    for(int i=1;i<=m;i++)   cin>>w[i];
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        ll tt;
        for(int j=1;j<=k;j++){
            cin>>a[i]>>tt;
            t[a[i]][i]=tt;
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                g[a[j]].push_back({a[l],i});
                g[a[l]].push_back({a[j],i});
            }
        }
    }
    while(q--){
        cin>>x>>y;
        memset(dis,-1,sizeof dis);
        bfs(x);
        cout<<0;
    }
    return 0;
}
