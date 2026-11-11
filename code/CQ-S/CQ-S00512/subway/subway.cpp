#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{typedef long long ll;typedef pair<int,int>pii;
    constexpr int maxn=503,maxm=5e5+3;
    constexpr ll inf=0x3f3f3f3f3f3f3f3f;ll dist[maxn][maxn];
    vector<pii>train[maxn],plate[maxm];int wei[maxm];
    inline void check_min(ll&var,ll val){if(var>val)var=val;}
    inline int Main(){int testcase,n,m,deg,q;cin>>testcase>>n>>m>>deg>>q;
        for(int i=1;i<=m;++i)cin>>wei[i];
        for(int i=1;i<=n;++i){int num;cin>>num,train[i].resize(num);
            for(int j=0,a,t;j<num;++j)cin>>a>>t,
                train[i][j]=pii(a,t),plate[a].push_back(pii(i,t));}
        memset(dist,0x3f,sizeof(dist));for(int i=1;i<=n;++i){dist[i][i]=0;
            for(const pii&j:train[i])for(const pii&k:plate[j.first])
                check_min(dist[i][k.first],j.second+k.second);}
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)
            check_min(dist[j][k],dist[j][i]+dist[i][k]);
        while(q--){int x,y;cin>>x>>y;ll ans=inf;
            for(const pii&i:plate[x])for(const pii&j:plate[y])
                check_min(ans,dist[i.first][j.first]+i.second+j.second);
            cout<<ans+wei[x]+wei[y]<<'\n';
        }return 0;
    }
}
int main(){//clock_t now=clock();
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),SOLUTION::Main()/*,
    clog<<"time:"<<double(clock()-now)/CLOCKS_PER_SEC<<"s\n"*/;return 0;
}