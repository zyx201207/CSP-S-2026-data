#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n;
long long d;
long long x[N];
int l[N],r[N];
namespace bf{
    const int _N=5e3+5;
    int dis[_N][_N],cnt[_N][_N];
    bitset<_N> vis;
    void work(){
        for(int i=1;i<=n;i++){
            dis[i][i]=0;
            cnt[i][i]=1;
            vis.reset();
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                //cout<<i<<"."<<u<<'\n';
                if(vis[u])continue;
                vis[u]=true;
                for(int v=(u<=i?l[u]:u+1);v<=(u>=i?r[u]:u-1);v++){
                    //cout<<u<<"->"<<v<<'\n';
                    if(dis[i][v]>dis[i][u]+1){
                        dis[i][v]=dis[i][u]+1;
                        cnt[i][v]=cnt[i][u];
                        q.push(v);
                    }else if(dis[i][v]==dis[i][u]+1)cnt[i][v]+=cnt[i][u];
                }
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    memset(bf::dis,0x3f,sizeof bf::dis);
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        x[0]=x[1]-d-1;
        x[n+1]=x[n]+d+1;
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(x,x+n+1,x[i]-d)-x;
            r[i]=upper_bound(x,x+n+1,x[i]+d)-1-x;
        }
        bf::work();
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((i<j)&&(bf::cnt[i][j]==2))ans++;
                bf::cnt[i][j]=0;
                bf::dis[i][j]=0x3f3f3f3f;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}