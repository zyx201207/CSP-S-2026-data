#include<bits/stdc++.h>
using namespace std;
int t,c,n,k,fa[500];
vector<int> e[500];
int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
int countbit(int x)
{
    int res=0;
    while(x) res++,x-=x&(-x);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        iota(fa+1,fa+n+1,1);
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
        for(int s=0;s<(1<<n);s++)
        {
            if(butilin_popcount(s)==k)
            {

            }
        }
    }*/
    cout<<countbit(3);

    return 0;
}
