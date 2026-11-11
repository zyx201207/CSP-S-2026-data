#include<bits/stdc++.h>
using namespace std;
namespace RST
{
    vector<int>eg[1000005];
    int d[1000005],ld[1000005],lld[1000005];
    int f[1000005],sz[1000005];
    int dp[4005][4005];
    int n,K;
    void dfs(int id,int fa)
    {
        d[id]=d[fa]+1;
        f[id]=fa;
        ld[id]=d[id];
        for(auto i:eg[id])
        {
            if(i==fa)
            {
                continue;
            }
            dfs(i,id);
            ld[id]=max(ld[id],ld[i]);
        }
    }
    void calc(int id)
    {
        dp[id][1]=0;
        sz[id]=1;
        multiset<int,greater<int> >st;
        st.insert(lld[id]);
        for(auto i:eg[id])
        {
            if(i==f[id])
            {
                continue;
            }
            st.insert(ld[i]-d[i]);
        }
        for(auto i:eg[id])
        {
            if(i==f[id])
            {
                continue;
            }
            st.erase(ld[i]-d[i]);
            lld[i]=*(st.begin())+1;
            st.insert(ld[i]-d[i]);
            calc(i);
            for(int j=min(sz[id]+sz[i],K);j>=1;j--)
            {
                int l=max(1,j-sz[id]);
                int r=min(sz[i],j);
                dp[id][j]=max(dp[id][j],ld[i]-d[id]);
                for(int k=l;k<=r;k++)
                {
                    dp[id][j]=min(dp[id][j],max(dp[id][j-k],dp[i][k]));
                }
            }
            sz[id]+=sz[i];
        }
    }
    void solve()
    {
        
        cin>>n>>K;
        for(int i=1;i<=n;i++)
        {
            eg[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=K;j++)
            {
                dp[i][j]=1e9;
            }
        }
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        lld[1]=0;
        dfs(1,0);
        calc(1);
        int ans=2e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=1;k<K;k++)
                {
                    ans=min(ans,max({dp[i][k],dp[j][K-k],min(lld[i],lld[j])}));
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,max(dp[i][K],lld[i]));
        }
        cout<<ans<<"\n";
        return ;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t=1;
    cin>>c>>t;
    while(t--)
    {
        RST::solve();
    }
    return 0;
}//g++ -o hub.exe hub.cpp -lm -O2 -std=c++14 -Wall -Wl,--stack=1000000000