#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=510,D=30;
int w[N];
int a[M][D],t[M][D];
int xian[N],weizhi[N];
vector<int>e[D];
int ans=0;
void dfs(int x,int y,int cnt,int now)
{
    for(int i=0;i<e[now].size();i++)
    {
            
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c>7||c<19)
    {
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
            xian[a[i][j]]=i;
            weizhi[a[i][j]]=j;
            if(j!=1)
            {
                e[lst].push_back(a[i][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dfs(x,y,0,x);
        cout<<ans<<endl;
    }
    return 0;
}
