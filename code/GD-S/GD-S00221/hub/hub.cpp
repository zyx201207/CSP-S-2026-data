#include<iostream>
#include<limits>
#include<vector>
using namespace std;
unsigned int popcount(unsigned int x)
{
    unsigned int res=0;
    while(x)
    {
        res+=(x&1);
        x>>=1;
    }
    return res;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> edges(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            edges[u].emplace_back(v);
            edges[v].emplace_back(u);
        }
        int tot=1;
        vector<int> marked(n+1);
        vector<int> visited(n+1);
        int ans=numeric_limits<int>::max()>>1;
        for(unsigned int mark=1;mark<(1<<n);mark++)
        {
            if(popcount(mark)==k)
            {
                for(unsigned int j=0;j<n;j++)
                {
                    if(mark&(1<<j))
                    {
                        marked[j+1]=tot;
                    }
                }
                auto dfs1=[&](auto&& self,const int from,const int father) -> void
                {
                    visited[from]=tot;
                    for(auto const to:edges[from])
                    {
                        if(to!=father&&marked[to]==tot)
                        {
                            self(self,to,from);
                        }
                    }
                };
                int cnt_blocks=0;
                for(int i=1;i<=n;i++)
                {
                    if(visited[i]!=tot&&marked[i]==tot)
                    {
                        cnt_blocks++;
                        dfs1(dfs1,i,-1);
                    }
                }
                if(cnt_blocks<=2)
                {
                    vector<int> DP1(n+1,numeric_limits<int>::max()>>1);
                    vector<int> DP2(n+1,numeric_limits<int>::max()>>1);
                    auto dfs2=[&](auto&& self,const int from,const int father) -> void
                    {
                        if(marked[from]==tot)
                        {
                            DP1[from]=0;
                        }
                        for(auto const to:edges[from])
                        {
                            if(to!=father)
                            {
                                self(self,to,from);
                                DP1[from]=min(DP1[from],DP1[to]+1);
                            }
                        }
                    };
                    dfs2(dfs2,1,-1);
                    int res=0;
                    auto dfs3=[&](auto&& self,const int from,const int father) -> void
                    {
                        if(marked[from]==tot)
                        {
                            DP2[from]=0;
                        }
                        if(father!=-1)
                        {
                            DP2[from]=min(DP2[from],DP2[father]+1);
                        }
                        DP2[from]=min(DP2[from],DP1[from]);
                        res=max(res,DP2[from]);
                        for(auto const to:edges[from])
                        {
                            if(to!=father)
                            {
                                self(self,to,from);
                            }
                        }
                    };
                    dfs3(dfs3,1,-1);
                    ans=min(ans,res);
                }
                tot++;
            }
        }
        cout<<ans<<'\n';
    }
}

