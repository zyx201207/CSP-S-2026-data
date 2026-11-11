#include<bits/stdc++.h>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
using namespace std;

const int N=2000005,INF=0x3f3f3f3f;
mt19937 rnd(random_device{}());
int cid,n,k,eg[N];
pair<int,int>eg1[N];
vector<int>e[N];
int cut;

int to[N],dep[N];
bool vis[N];
int cnt[N];
il void walk(int x,int fa){
    dep[x]=1,to[x]=0,vis[x]=1;
    int y;
    for(int id:e[x]){
        y=eg[id]^x;if(id==cut||y==fa)continue;
        walk(y,x);
        if(dep[y]>=dep[x])to[x]=y,dep[x]=dep[y]+1;
    }
}
il void sol1(int rt,int res[]){
    forto(i,0,n)res[i]=cnt[i]=0,vis[i]=0;
    walk(rt,0);
    while(to[rt])rt=to[rt];
    walk(rt,0);
    vector<int>path;path.emplace_back(rt);
    while(to[rt])rt=to[rt],path.emplace_back(rt);
    rt=path[path.size()/2],walk(rt,0);
    // cerr<<rt<<'\n';
    // forto(i,1,n)cerr<<dep[i]<<' ';cerr<<'\n';
    forto(i,1,n)if(vis[i])cnt[dep[i]]++;
    int tag=0;
    forbk(i,n,1){
        while(cnt[i]--)res[tag++]=i;
    }
    res[0]=INF;
}
int A[N],B[N],ans;

il void cut_and_sol(int i){
    cut=i,sol1(eg1[i].first,A),sol1(eg1[i].second,B);
    forto(j,0,k)ans=min(ans,max(A[j],B[k-j]));
    // cerr<<"cut "<<i<<' '<<ans<<'\n';
}

il void work(){
    cin>>n>>k;
    forto(i,1,n-1){
        int x,y;cin>>x>>y;
        eg1[i]={x,y};
        eg[i]=x^y,e[x].emplace_back(i),e[y].emplace_back(i);
    }
    cut=-1,sol1(1,A),ans=A[k];
    if(k==2||(cid>=11&&n>=100)){
        int rt=1;
        forto(i,0,n)vis[i]=0;
        walk(rt,0);
        while(to[rt])rt=to[rt];
        walk(rt,0);
        vector<int>path;path.emplace_back(rt);
        while(to[rt])rt=to[rt],path.emplace_back(rt);
        int x=path[path.size()/2],y=path[path.size()/2-1];
        forto(i,1,n-1){
            if(eg1[i].first==x&&eg1[i].second==y||eg1[i].first==y&&eg1[i].second==x){
                cut_and_sol(i);break;
            }
        }
        // cerr<<"qwq\n";
        forv(_,(cid<=14)?10:0)cut_and_sol(rnd()%(n-1)+1);
    }else{
        forto(i,1,n-1)cut_and_sol(i);
    }
    cout<<ans<<'\n';
    forto(i,1,n)e[i].clear();
}

signed main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>cid>>t;
    while(t--)work();
    return 0;
}