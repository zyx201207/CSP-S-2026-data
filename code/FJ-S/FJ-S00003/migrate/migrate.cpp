#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,T,n,sum[N];
ll d,x[N],dis[N];
vector<int> e[N];
void dfs(int u,int D){
    if(D==dis[u]) sum[u]++;
    else if(D<dis[u]) dis[u]=D,sum[u]=1;
    else return;
    for(int v:e[u])
        dfs(v,D+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c<=6){
            int ans=0;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(x[j]-x[i]<=d) e[i].push_back(j);
            for(int i=1;i<=n;i++) reverse(e[i].begin(),e[i].end());
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++) sum[j]=0,dis[j]=1e18;
                dfs(i,0);
                for(int j=i+1;j<=n;j++)
                    if(sum[j]==2) ans++;
            }
            cout<<ans<<'\n';
            continue;
        }
        if(c==11||c==12){
            ll D=x[2]-x[1];
            if(!D){cout<<"0\n";continue;}
            ll cnt=(ll)(floor)(1.0*d/D);
            if(!cnt||cnt==1){cout<<"0\n";continue;}
            ll ans=0;
            for(int i=1;i<=n-1;i++)
                if(i%cnt==cnt-1&&i/cnt==1) ans+=n-i;
            cout<<ans<<'\n';
            continue;
        }

    }
}