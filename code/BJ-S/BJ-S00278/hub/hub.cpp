#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=11;
int c,t;
int n,k;
vector<int> e[maxn];
int ans=0;
int suan(int x){
    int sum=0;
    while(x){
        if(x&1) sum++;
        x>>=1;
    }
    return sum;
}
bool f[maxn],flag[maxn];
int d[maxn];
void dfs1(int u){
    flag[u]=1;
    for(int v:e[u]){
        if(!f[v]) continue;
        if(flag[v]) continue;
        dfs1(v);
    }
}
void dfs2(int u){
    for(int v:e[u]){
        if(d[v]>d[u]+1){
            d[v]=d[u]+1;
            dfs2(v);
        }
    }
}
int dis(){
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++){
        if(f[i]){
            d[i]=0;
            dfs2(i);
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        //cout<<d[i]<<" ";
        sum=max(sum,d[i]);
    }
    //cout<<'\n';
    return sum;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans=1e9;
        for(int i=0;i<(1<<n);i++){
            if(suan(i)!=k){
                continue;
            }
            //cout<<"GGG\n";
            int cnt=0;
            for(int j=1;j<=n;j++){
                f[j]=flag[j]=0;
                if(i&(1<<(j-1))){
                    f[j]=1;
                    //cout<<j<<" ";
                }
            }
            //cout<<'\n';
            for(int j=1;j<=n;j++){
                if(!f[j]) continue;
                if(!flag[j]){
                    dfs1(j);
                    cnt++;
                }
            }
            //cout<<cnt<<'\n';
            if(cnt==2){
                int p=dis();
                //cout<<p<<'\n';
                ans=min(ans,p);
            }
            //cout<<"HHH\n";
        }
        cout<<ans<<'\n';
    }
    return 0;
}

