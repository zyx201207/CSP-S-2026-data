#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,rt,hi,ans,res,mmax,smax;
int u[1000010],v[1000010];
vector<int> vc[1000010];
int dp[1000010],h[1000010],fa[1000010];
inline int dep(int x,int d)
{
    dp[x]=d;
    if(vc[x].size()==0)
    {
        h[x]=0;
        return 0;
    }
    for(auto i:vc[x])
    {
        h[x]=max(h[x],dep(i,d+1)+1);
    }
    return h[x];
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
            if(u[i]>v[i])
            {
                swap(u[i],v[i]);
            }
            fa[v[i]]=u[i];
            vc[u[i]].push_back(v[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==0)
            {
                rt=i;
                break;
            }
        }
        hi=dep(rt,0);
        ans=0x7f7f7f7f;
        mmax=0;smax=0;
        for(auto i:vc[rt])
        {
            if(h[i]+1>mmax)
            {
                mmax=h[i]+1;
                smax=mmax;
            }
            else if(h[i]+1>smax)
            {
                smax=h[i]+1;
            }
        }
        ans=(mmax+smax-k+2)/2;
        cout<<ans<<endl;

    }
    return 0;
}
