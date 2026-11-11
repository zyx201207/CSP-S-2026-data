#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+100;
int n,d;
int x[mx];
int read()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
    return x*w;
}
void write(int x)
{
    if(x<0) putchar('-'),x*=-1;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
    return ;
}
int vis[mx];
int sum=0;
int len=0;
int minn=1e9;
void dfs(int u,int en)
{
    if(len>minn) return;
    if(u==en&&len==minn) 
    {
        sum++;
        return ;
    }
    else if(u==en&&len<minn)
    {
        minn=len,sum=1;
        return ;
    }
    else if(u==en) return ;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||abs(x[u]-x[i])>d) continue;
        vis[i]=1;
        len++;
        dfs(i,en);
        len--;
        vis[i]=0;
    }
}
bool che(int u,int v)
{
    sum=0;
    len=0;
    minn=1e9;
    for(int i=1;i<=n;i++) vis[i]=0;
    vis[u]=1;
    dfs(u,v);
    // cout<<sum<<endl;
    if(sum==2) return 1;
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    while(T--)
    {
        n=read(),d=read();
        for(int i=1;i<=n;i++) x[i]=read();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                // cout<<i<<' '<<j<<endl;
                if(che(i,j)) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}