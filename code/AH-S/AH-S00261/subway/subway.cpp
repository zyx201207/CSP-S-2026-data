#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using pii=pair<int,int>;
using pll=pair<long long,long long>;

ll c,n,m,d,q;
const ll D=25, M=5E5+10,N=510,inc=0x3f3f3f3f3f3f3f3f;
ll adj[N][M];
ll sta[M];
ll ans=1E18;
bool exist [M];
void dfs(ll u,ll len,ll o,ll b){
    if(b==u) {
            ans=min(ans,len);
            return ;
    }
    if(len>=ans) return;
    if(o==n+1) return;
    exist[u]=true;
    for(int i=1;i<=m;i++) {
        if(i==u or exist[i]==true) continue;
        if(adj[o][u]>=inc) break;
        if(adj[o][i]>=inc) continue;
        dfs(i,len+adj[o][u]+adj[o][i],o+1,b);
    }
    dfs(u,len,o+1,b);
    exist[u]=false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);

    memset(adj,0x3f,sizeof(adj));

    cin>>c>>n>>m>>d>>q;


    for(int i=1;i<=m;i++) cin>>sta[i];
    for(int i=1;i<=n;i++ ) {
        int k;
        cin>>k;
        ll x1,x2;
        for(int j=1;j<=k;j++) {
            ll a,t;
            cin>>a>>t;
            if(j==1) x1=a;
            else x2=a;
            adj[i][a]=t;
        }

    }



    if(1<=c and c<=8) {
        for(int i=1;i<=q;i++) {
            ll l,r;
            cin>>l>>r;
            fill(exist,exist+m+1,false);
            ans=1E18;
            if(l>r) swap(l,r);
            dfs(l,0,1,r);
            cout<<ans+sta[l]+sta[r]<<"\n";
        }
    }

    return 0;
}

