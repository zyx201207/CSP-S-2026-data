#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define int long long
#define P pair<int,int>
using namespace std;
constexpr int N=2e6+10;
constexpr int INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,s,t;
int a[N],res,cnt,ans;
inline void bfs(){
    priority_queue<P,vector<P>,greater<P> > q;
    q.push({0,s});
    res=INF;
    cnt=0;
    while(!q.empty()){
        P cur=q.top();
        q.pop();
        int sum=cur.first;
        int u=cur.second;
        if(sum>res) continue;
        if(a[t]-a[u]<=d){
            if(res==INF) res=sum;
            ++cnt;
            if(cnt>2) break;
            continue;
        }
        for(int i=u+1;i<=n;++i){
            if(a[i]-a[u]>d) break;
            q.push({sum+1,i});
        }
    }
    if(cnt==2) ++ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    if(c<=10){
        while(T--){
            ans=0;
            cin>>n>>d;
            F(i,1,n) cin>>a[i];
            F(i,1,n){
                F(j,i+1,n){
                    s=i,t=j;
                    bfs();
                }
            }
            cout<<ans<<'\n';
        }
    }
}