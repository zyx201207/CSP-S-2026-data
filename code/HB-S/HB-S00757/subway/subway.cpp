#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c,n,m,d,q;
vector<int> dist1;
vector<vector<int>> to_s;
vector<vector<int>> lengths;
long long int dists[501][501];
bool lt[501][501];

void init()
{
    cin>>c>>n>>m>>d>>q;
    dist1.resize(m+1,0);
    to_s.resize(m+1,{});
    lengths.resize(m+1,{});
    for(int i=1;i<=m;i++)cin>>dist1[i];
    for(int i=1;i<=m;i++)
    {
        to_s[i].reserve(21);
        lengths[i].reserve(21);
    }
    for(int i=1;i<=n;i++)
    {
        int nums;
        cin>>nums;
        int a,t;
        for(int j=1;j<=nums;j++)
        {
            cin>>a>>t;
            to_s[a].push_back(i);
            lengths[a].push_back(t);
        }
    }

    for(int i=1;i<=500;i++)for(int j=1;j<=500;j++)dists[i][j] = (long long int)(4e18)+1;
    for(int i=1;i<=500;i++)dists[i][i] = 0;
    for(int i=1;i<=500;i++)for(int j=1;j<=500;j++)lt[i][j] = false;
    for(int i=1;i<=500;i++)lt[i][i] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    init();
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<(int)to_s[i].size();j++)
        {
            for(int k=j+1;k<(int)to_s[i].size();k++)
            {
                lt[to_s[i][j]][to_s[i][k]] = lt[to_s[i][k]][to_s[i][j]] = true;
                dists[to_s[i][j]][to_s[i][k]] = dists[to_s[i][k]][to_s[i][j]] = min((long long int)(lengths[i][j]+lengths[i][k]),dists[to_s[i][j]][to_s[i][k]]);
            }
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=k;i++)
        {
            if(lt[k][i])
            {
                for(int j=1;j<=k;j++)
                {
                    dists[k][j] = dists[j][k] = min(dists[k][j],dists[k][i]+dists[i][j]);
                }
            }
        }
        for(int i=1;i<=k;i++)for(int j=1;j<=k;j++)dists[i][j] = dists[j][i] = min(dists[i][j],dists[i][k]+dists[j][k]);
    }

    int u,v;
    for(int i=1;i<=q;i++)
    {
        cin>>u>>v;
        long long int ans = 4e18;
        for(int j=0;j<(int)to_s[u].size();j++)
        {
            for(int k=0;k<(int)to_s[v].size();k++)
            {
                ans = min(ans,dists[to_s[u][j]][to_s[v][k]]+lengths[u][j]+lengths[v][k]);
            }
        }
        cout<<(dist1[u]+dist1[v]+ans)<<'\n';
    }
/*
    for(int i=1;i<dist1.size();i++)cout<<dist1[i]<<' ';
    cout<<'\n';
    for(int i=1;i<to_s.size();i++)
    {
        for(int j=0;j<to_s[i].size();j++)
        {
            cout<<to_s[i][j]<<' '<<lengths[i][j]<<' ';
        }cout<<'\n';
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dists[i][j]<<' ';
        }
        cout<<'\n';
    }
*/
}