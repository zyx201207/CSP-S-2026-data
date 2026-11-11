#include<bits/stdc++.h>
using namespace std;
long long t[500010],k[510],dis[500010];
map<long long,long long> mp,mp2;
vector<long long> a[510],change[510];
vector<pair<long long,long long>> adj[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++) cin>>t[i];
    for(long long i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].push_back(0);
        change[i].push_back(0);
        for(long long j=1;j<=k[i];j++)
        {
            long long temp1,temp2;
            cin>>temp1>>temp2;
            a[i].push_back(temp1);
            change[i].push_back(temp2);
        }
        for(long long j=1;j<=k[i];j++)
            for(long long z=1;z<=k[i];z++)
                if(j!=z) adj[a[i][j]].push_back({a[i][z],change[i][j]+change[i][z]});
    }
    if(20<=c&&c<=21)
    {
        for(long long j=1;j<=k[1];j++) mp[a[1][j]]=j;
        if(n==1)
        {
            while(q--)
            {
                long long s,e;
                cin>>s>>e;
                cout<<t[s]+change[1][mp[s]]+change[1][mp[e]]+t[e]<<'\n';
            }
            return 0;
        }
        for(long long j=1;j<=k[1];j++) mp2[a[2][j]]=j;
        while(q--)
        {
            long long s,e;
            cin>>s>>e;
            long long ans=1e18;
            if(mp.count(s)&&mp.count(e)) ans=t[s]+change[1][mp[s]]+change[1][mp[e]]+t[e];
            if(mp2.count(s)&&mp2.count(e)) ans=min(ans,t[s]+change[2][mp[s]]+change[2][mp[e]]+t[e]);
            for(long long i=1;i<=m;i++)
            {
                if(i==e||i==s) continue;
                if((!mp.count(i))||(!mp2.count(i))) continue;
                if(mp.count(s)&&mp2.count(e)) ans=min(ans,t[s]+change[1][mp[s]]+change[1][mp[i]]+change[2][mp2[i]]+change[2][mp2[e]]+t[e]);
                if(mp.count(e)&&mp2.count(s)) ans=min(ans,t[s]+change[2][mp2[s]]+change[2][mp2[i]]+change[1][mp[i]]+change[1][mp[e]]+t[e]);
            }
            cout<<ans<<'\n';
        }
    }
    while(q--)
    {
        memset(dis,0x6f,sizeof(dis));
        long long s,e;
        cin>>s>>e;
        queue<long long> q;
        dis[s]=0;
        q.push(s);
        while(q.size())
        {
            long long t=q.front();
            q.pop();
            for(auto i:adj[t])
            {
                long long x=i.first,num=i.second;
                if(dis[x]<=dis[t]+num) continue;
                dis[x]=dis[t]+num;
                q.push(x);
            }
        }
        cout<<dis[e]+t[s]+t[e]<<'\n';
    }
    return 0;
}
