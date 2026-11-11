#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,INF=0x3f3f3f3f;
int c,t,n,m,ans,d[N],f[N];//x cnt has[xx]
vector<int>g[N];
int dfs1(int xx,int lx,int cnt,int sum){
    bool flag=((sum&(1<<xx-1))==xx);
    if(flag){
        d[xx]=0;
    }else{
        d[xx]=cnt;
    }
    int mn=INF;
    f[xx]=0;
    for(auto nx:g[xx]){
        if(nx==lx){
            continue;
        }
        mn=min(mn,dfs1(nx,xx,((flag)?0:cnt+1),sum)+1);
        f[xx]=max(f[xx],f[nx]);
    }
    d[xx]=min(d[xx],mn);
    f[xx]=max(f[xx],d[xx]);
    //cout<<xx<<' '<<d[xx]<<' '<<f[xx]<<'\n';
    if(flag){
        mn=0;
    }
    return mn;
}
int lowbit(int sum){
    return sum&(-sum);
}
int cnt(int sum){
    int ans=0;
    while(sum){
        sum-=lowbit(sum);
        ans++;
    }
    return ans;
}
void dfs(int x,int sum){
    if(x>n){
        if(cnt(sum)==m){
            //cout<<sum<<'\n';
            dfs1(1,0,INF,sum);
            ans=min(ans,f[1]);
        }
        return;
    }
    //cout<<x<<' '<<sum<<'\n';
    dfs(x+1,sum<<1);
    dfs(x+1,sum<<1|1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    //cout<<t<<'\n';
    while(t--){
        cin>>n>>m;
        //cout<<n<<' '<<m<<'\n';
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==m){
            cout<<0<<'\n';
            continue;
        }else if(c>3){
            cout<<n/m<<'\n';
            continue;
        }
        ans=INF;
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
