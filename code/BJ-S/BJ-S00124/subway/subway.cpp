#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int lj[10005][10005];
int ans=1e9;
bool visited[35];
int t[505][500005];
int w[500005];
int a[30][505];
int c,n,m,d,q;
void bfs(int s,int f)
{
    queue<int>q;
    int ans1;
    while(!q.empty())
    {
        int x=q.front();
        q.back();
        if(x==f)
        {
            ans=min(ans,ans1);
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            if(lj[x][i]==1e9)continue;
            if(visited[i])continue;
            visited[i]=1;
            ans1+=lj[x][i];
            q.push(i);
        }
    }
}
int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)lj[i][j]=1e9;
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][k]>>t[i][k];
            for(int r=1;r<j;r++)lj[r][a[i][k]]=min(lj[r][a[i][k]],t[i][r]+t[i][k]);
        }
    }
    while(q--)
    {
        int s,f;
        cin>>s>>f;
        ans=1e9;
        bfs(s,f);
        cout<<ans;
    }
}