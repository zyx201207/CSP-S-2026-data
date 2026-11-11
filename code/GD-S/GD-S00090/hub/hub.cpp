#include<bits/stdc++.h>
using namespace std;  typedef long long LL; 
#define rep(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
#define reb(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1>=__##_1##__; --_1)
const int N=20004, M=0, K=0; 
int n, k, use[N], ans;
int hea[N], nex[N<<1], to[N<<1], cte, dis[N];
char bz[N];
void ae(int x, int y) { ++cte, nex[cte]=hea[x], hea[x]=cte, to[cte]=y; }
void mark(int x) { bz[x]='#'; for(int it=hea[x]; it; it=nex[it]) { int y=to[it];  if(bz[y]=='$') mark(y); } }
int bfs(int u) {
    if(bz[u]) return 0;
    rep(i,1,n) dis[i]=0x3F3F3F3F;
    queue<int> q;  q.push(u), dis[u]=0;
    while(!q.empty()) {
        int x=q.front();  q.pop();
        for(int it=hea[x]; it; it=nex[it]) { int y=to[it];  if(dis[y]==0x3F3F3F3F) { q.push(y), dis[y]=dis[x]+1; 
            if(bz[y]=='#') { return dis[y]; }} }
    }
    return 0x3F3F3F3F;
}

void Search(int id, int step) {
    if(n-id+1<step) return ;
    else if(!step) {
        rep(i,1,k) bz[use[i]]='$';
        char ch='\2';
        rep(i,1,k) { if(bz[use[i]]=='$') { if(!ch) { ch='#'; break; } mark(use[i]), --ch; } }
        if(ch=='#') return ; // If the connectingÐblocks is at least 3
        int reu=0;
        rep(i,1,n) reu=max(reu, bfs(i));
        ans=min(ans, reu);
        rep(i,1,k) bz[use[i]]='\0';
        return ;
    }
    use[step]=id, Search(id+1, step-1); // Select
    Search(id+1, step); // not select
}

bool __main() {
    cin>>n>>k;  cte=0;  rep(i,1,n) hea[i]=0;
    rep(i,1,n-1) { int x=0, y=0;  cin>>x>>y;  ae(x,y), ae(y,x); }
    ans=0x3F3F3F3F;
    Search(1,k);
    cout<<ans<<'\n';
    return 0;
}

int main() {
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
    int _=1, __=0;  cin>>__>>_;  for(; _>0; --_) if(__main()) return 0;
    return 0;
}