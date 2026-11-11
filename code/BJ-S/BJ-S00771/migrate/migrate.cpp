#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int a[N];
vector<pair<int,int>> g[N];
struct node{
    int x;
    ll w;
};
queue<node> q;
ll f[N];
int cnt[N];
void solve(){
    int n,m;
    int res=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        g[i].clear();
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[j]-a[i]<=m){
                g[i].push_back({j,1});
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            f[j]=INF;
            cnt[j]=0;
        }
        q.push({i,0});
        f[i]=0;
        while(!q.empty()){
            int x=q.front().x;
            ll w=q.front().w;
            q.pop();
            for(pair<int,int> y:g[x]){
                if(f[y.first]==f[x]+y.second){
                    ++cnt[y.first];
                }
                if(f[y.first]>f[x]+y.second){
                    cnt[y.first]=1;
                    if(f[y.first]==INF){
                        f[y.first]=f[x]+y.second;
                        q.push({y.first,f[y.first]});
                    }
                }
            }
        }
        for(int j=1;j<=n;++j){
            res+=(cnt[j]==2);
        }
    }
    cout<<res<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
