#include <bits/stdc++.h>
#define ll long long
#define sz(a) (int)(a).size()
#define mk make_pair
#define pb push_back
#define fir first
#define sec second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
/*
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
*/
const int N=5005;
ll n,d,x[N],vis[N],dis[N],cnt[N],bk[N][N];
struct fireup{
    int pos;ll dis;

    bool operator<(const fireup &x)const{
        return x.dis<dis;
    }

};
vector<int>g[N];
void bfs(int st){
    memset(cnt,0,sizeof cnt);
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    dis[st]=0;
    priority_queue<fireup>q;
    q.push({st,0});
    while(!q.empty()){
        int u=q.top().pos;
        q.pop();
        if(vis[u]==1)continue;
        vis[u]=1;
        for(auto v:g[u]){
            if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                q.push({v,dis[v]});
                cnt[v]=1;
            }
            else if(dis[v]==dis[u]+1) cnt[v]++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,_;
    cin>>c>>_;
    while(_--){
            memset(bk,0,sizeof bk);
        cin>>n>>d;
        rep(i,1,n) {
            cin>>x[i];
        }
        rep(i,1,n){
            rep(j,i+1,n)
                if(abs(x[i]-x[j])<=d){
                    g[i].pb(j);
                    //bk[i][j]=1;
                }
                else break;
        }
        //bfs(1);
        //rep(i,1,n) cout<<dis[i]<<" ";
        int ans=0;
        rep(i,1,n) {
            bfs(i);
            rep(j,1,n) if(i!=j&&cnt[j]==2){ans++;
            //cout<<i<<" "<<j<<"\n";      }
            //cout<<cnt[i]<<" ";
        }
        }
        cout<<ans<<'\n';
    }
    return  0;
}
/*
g++ Untitled.cpp -o Untitled -O2 -std=c++14
g++  home user Untitled.cpp -o Untitled -O2 -std=c++14
0 2
4 2 1 2 3 4
5 2 1 2 3 4 5
*/
