#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[101],n,m,k;
int get(int i)
{
    if(fa[i]==i)
    {
        return i;
    }
    return fa[i]=get(fa[i]);
}
void uinint(int x,int y)
{
    fa[get(x)]=get(y);
}
void inint()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
}
vector<int> g[101];
int book[101];
int ans;
int q[101];int f[101][101];
void dfs(int pos)
{
    if(pos==n+1)
    {
        inint();
        for(int i=1;i<pos;i++)
        {
            for(int j:g[i])
            {
                if(get(i)!=get(j))
                {
                    uinint(i,j);
                }
            }
        }
        int cnt=0;
        int vis[101]={0};
        for(int i=1;i<=n;i++)
        {
            if(vis[fa[i]]==0)
            {
                vis[fa[i]]=1;
                cnt++;
            }
        }
        if(cnt<=2)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(book[i]==0)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(book[j]==1)
                        {
                            cnt=max(cnt,f[min(i,j)][max(i,j)]);
                        }
                    }
                }
            }
            ans=min(ans,cnt);
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            q[pos]=i;
            book[i]=1;
            dfs(pos+1);
            book[i]=0;
        }
    }
}


    
signed main()
{
 freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        ans=0x3f3f3f3f3f3f3f3f;
        
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            f[x][y]=f[y][x]=1;
        }
            for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
    }
    for(int len=3;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for(int k=l;k<r;k++)
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
            }
        }
    }
    dfs(1);
    cout<<ans<<'\n';
    }
    return 0;
}
