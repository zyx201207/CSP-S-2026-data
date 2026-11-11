#include<bits/stdc++.h>
#define int long long
#define pll pair<long long,long long>
using namespace std;
int c,n,m,d,q,dis[500505],st[500505],cst[500005],ans[100005];
struct questions{
    int fir,sec,num;
}p[100005];
vector<vector<pll>>v(500505);
bool cmp(questions x,questions y){
    return x.fir<y.fir;
}
void dijkstra(int start){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<pll,vector<pll>,greater<pll>>q;
    dis[start]=0;
    q.push({0,start});
    while(!q.empty()){
        auto x1=q.top();
        q.pop();
        int val=x1.first,u=x1.second;
        if(st[u])continue;
        st[u]=1;
        for(auto x:v[u]){
            int r1=x.first,r2=x.second;
            if(val+r2<dis[r1]){
                dis[r1]=val+r2;
                q.push({dis[r1],r1});
            }
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>cst[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int a,b;
            cin>>a>>b;
            v[a+n].push_back({i,b});
            v[i].push_back({a+n,b});
        }
    }
    for(int i=1;i<=q;++i){
        cin>>p[i].fir>>p[i].sec;
        p[i].num=i;
    }
    sort(p+1,p+q+1,cmp);
    int dijd=0;
    for(int i=1;i<=q;++i){
        if(dijd!=p[i].fir+n){
            dijd=p[i].fir+n;
            dijkstra(dijd);
        }
        ans[p[i].num]=dis[p[i].sec+n]+cst[p[i].fir]+cst[p[i].sec];
    }
    for(int i=1;i<=q;++i)cout<<ans[i]<<endl;
    return 0;
}
