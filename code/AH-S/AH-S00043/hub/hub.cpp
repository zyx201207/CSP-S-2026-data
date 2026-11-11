/*

cd ~/draft && ulimit -s 1048576 && g++ hub.cpp -std=c++14 -O2 -Wall -fsanitize=address,leak,undefined -o hub && ./hub

*/
#include <bits/stdc++.h>
using namespace std;
#define upp(x,y,z) for(x=(y);x<=(z);x++)
#define low(x,y,z) for(x=(y);x>=(z);x--)
#define fs(x) fixed<<setprecision(x)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define line '\n'
const int ext=0xf; const int N=1e5+ext; const int mod=998244353; const int inf=0x3fffffff;
template<typename t0> void ckmax(t0 &x,t0 y){if(x<y){x=y;} }
template<typename t0> void ckmin(t0 &x,t0 y){if(x>y){x=y;} }
void code(); void io(); void perf(); int main(){io(); code(); perf(); return 0;}
bool mb;
int c,t,n,k,cnt,now,tot,ans; vector<int> p[N]; bool tag[N],vis[N];
void dfs2(int x){
    vis[x]=1;
    for(auto i:p[x]){
        if((vis[i]==0)&&(tag[i]==1)){dfs2(i);}
    }
}
void dfs3(int x,int pre,int d){
    if(tag[x]==1){ckmin(now,d);}
    for(auto i:p[x]){
        if(i==pre){continue;}
        dfs3(i,x,d+1);
    }
}
void solve(){
    int i; upp(i,1,n){vis[i]=0;} cnt=0;
    upp(i,1,n){if((vis[i]==0)&&(tag[i]==1)){cnt++; dfs2(i);} }
    if(cnt>2){return;}
    tot=0; upp(i,1,n){now=inf; dfs3(i,0,0); ckmax(tot,now);}
    ckmin(ans,tot);
}
void dfs1(int x,int y){
    if(y==k){solve(); return;}
    if(x==n+1){return;}
    dfs1(x+1,y); 
    tag[x]=1;
    dfs1(x+1,y+1);
    tag[x]=0;
}
void code(){
    int i,j,x,y; cin>>c>>t; while(t--){
        cin>>n>>k;
        if((c>=0)&&(c<=3)){
            upp(i,1,n){p[i].clear();} ans=inf;
            upp(i,2,n){cin>>x>>y; p[x].pb(y); p[y].pb(x);}
            dfs1(1,0); cout<<ans<<line;
        }
        else{cout<<1<<line;}
    }
}
bool me;
void io(){
    freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void perf(){
    // cerr<<"Time used:"<<fs(3)<<1.0*clock()/CLOCKS_PER_SEC<<"s."<<endl;
    // cerr<<"Memory used:"<<fs(3)<<abs(1.0*(&me-&mb)/1024.0/1024.0)<<"MB."<<endl;
}