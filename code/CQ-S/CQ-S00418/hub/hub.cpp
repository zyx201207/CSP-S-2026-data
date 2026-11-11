#include<bits/stdc++.h>
#define ll long long
#define pii pair<int ,int >
#define pll pair<long long, long long >

using namespace std;
const ll N=1e6+5,M=505,W=1e9,mod=998244353,INF=1e18;
ll n,m,d,q,dis[N],ans=INF;
vector<int >ve[N];
struct dsu{
    int fa[N],cnt;
    int find(int x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
}dsu;
void sol(){
    ans=INF;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        ve[i].clear();
    }
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    if(n<=10){
        for(int i=0;i<(1<<n);++i){
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(i&(1<<j-1)){
                    ++cnt;
                }
            }
            if(cnt!=m)continue;
            queue<int >qu;
            dsu.cnt=m;
            for(int j=1;j<=n;++j){
                dis[j]=INF;
                if(i&(1<<j-1)){
                    ++cnt;
                    dis[j]=0;
                    dsu.fa[j]=j;
                    qu.push(j);
                }
            }
            for(int j=1;j<=n;++j){
                if(dis[j]==0){
                    for(int k:ve[j]){
                        if(!dis[k]){
                            int aa=dsu.find(j),bb=dsu.find(k);
                            if(aa!=bb){
                                dsu.cnt--;
                                dsu.fa[aa]=bb;
                            }
                        }
                    }
                }
            }
            if(dsu.cnt>2)continue;
            while(qu.empty()==0){
                int x=qu.front();
                qu.pop();
                for(auto i:ve[x]){
                    if(dis[i]>dis[x]+1){
                        dis[i]=dis[x]+1;
                        qu.push(i);
                    }
                }
            }
            ll maxx=-1;
            for(int j=1;j<=n;++j){
                maxx=max(maxx,dis[j]);
            }
            ans=min(ans,maxx);
            
        }
    }
    cout<<ans<<'\n';
    

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t=1;
    int c=0;
    //cin>>t;
    cin>>c>>t;
    while(t--){
        sol();
    } 
    //cerr<<clock();
    return 0;
}
/*
author:_aa_
14:34 AC crystal
15:23 AC subway
17:07 AC migrate
难呐难呐😭
*/
