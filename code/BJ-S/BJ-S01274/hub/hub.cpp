#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define w(x) cerr<<#x<<':'<<x<<endl
#define dbg cerr<<"\n----------------\n"
#define fi first
#define sc second
#define pii pair<int,int>
#define gc getchar_unlocked
#define pc putchar_unlocked
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;char c=gc();bool fl=1;
        while(c<'0' || c>'9'){if(c=='-') fl=0;c=gc();}
        while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-48,c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    void write(T x){
        if(x<0) x=-x,pc('-');
        if(x>9) write(x/10);
        pc('0'+x%10);
    }
    inline void read(char &c){while(isspace(c=gc()));}
    inline void write(char &c){pc(c);}
}using namespace IO;
const int inf=3e18;
const int mod=998244353;
const int N=3e5+5;
int c,T,n,m,x,y,z,l,r,k,L,now,sum,ans;
int a[N];
bool fl[N],vis[N];
vector<int> e[N];
void dfs2(int x,int fa){
    vis[x]=1;
    for(int v:e[x]){
        if(v==fa || !fl[v]) continue;
        dfs2(v,x);
    }
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=k;i++){
        if(!vis[a[i]]){
            cnt++;
            if(cnt>=3) return 0;
            dfs2(a[i],0);
        }
    }
    return 1;
}
int calc(){
    int res=0;
    queue<pii> q;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=k;i++){
        vis[a[i]]=1;
        q.push({a[i],0});
    }
//    dbg;
    while(!q.empty()){
        pii u=q.front();q.pop();
//        w(u.fi);
        res=u.sc;
        for(int v:e[u.fi]){
            if(!vis[v]){
                vis[v]=1;
                q.push({v,u.sc+1});
            }
        }
    }
//    dbg;
    return res;
}
void dfs(int x,int len){
    if(len==k){
        if(check()) ans=min(ans,calc());
        return ;
    }
    if(x==n+1) return ;
    a[len+1]=x,fl[x]=1;
    dfs(x+1,len+1);
    fl[x]=0;
    dfs(x+1,len);
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(),cout.tie();
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        ans=inf;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++) cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
        dfs(1,0);
        cout<<ans<<endl;
    }


    cerr<<endl<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
