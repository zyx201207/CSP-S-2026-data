#include <bits/stdc++.h>
using namespace std;
int n,m,d,q;
vector<int> w;
vector<int> k;
vector<int>a[505];
vector<int>t[505];
vector<int> x;
vector<int> y;
int sub[10000][10000];
bool vis[500001];
long long ans=0;
void dfs(int v,long long cnt,int goal)
{
    if(v==goal)
    {
        ans=max(cnt,ans);
        return;
    }
    vis[v]=true;
    for(int i=0;i<sub[v][0];i++)
    {
        if(!vis[v])
            dfs(i,cnt+sub[v][i],goal);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        int o;
        cin>>o;
        w.push_back(o);
    }
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        k.push_back(o);
        for(int j=0;j<k[i];j++)
        {
            cin>>o;
            a[i].push_back(o);
            cin>>o;
            t[i].push_back(o);
            sub[a[i][j]][m+i]=t[i][j];
            sub[a[i][j]][0]++;
            sub[m+i][a[i][j]]=t[i][j];
            sub[m+i][0]++;
        }
    }
/*
    for(int i=0;i<sub[1].size();i++)
    {
        cout<<sub[1][i]<<" ";
    }
*/
    for(int r=0;r<q;r++)
    {
        int o;
        cin>>o;
        x.push_back(o);
        cin>>o;
        y.push_back(o);
    }
    for(int r=0;r<q;r++)
    {
        ans=0;
        dfs(x[r],0,y[r]);
        ans+=w[x[r]];
        ans+=w[y[r]];

        cout<<ans<<'\n';
    }
    //cout<<"lezi";
    return 0;
}
