#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int t[1005][1005];
int f[1005][1005];
int w[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;c=read();n=read();m=read();d=read();q=read();
    memset(t,0,sizeof(t));
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k;k=read();
        if(k<=1)continue;
        int a1,t1;a1=read();t1=read();
        int a2,t2;a2=read();t2=read();
        if(t[a1][a2]!=0)
        {
            t[a1][a2]=min(t[a1][a2],t1+t2);
            t[a2][a1]=t[a1][a2];
        }
        else
        {
            t[a1][a2]=t1+t2;
            t[a2][a1]=t[a1][a2];
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=t[i][j];
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            if(f[i][k]==0)continue;
            for(int j=1;j<=m;j++)
            {
                if(f[k][j]==0)continue;
                if(f[i][j]==0)f[i][j]=f[i][k]+f[k][j];
                if(f[i][j]!=0) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int be,en;be=read();en=read();
        cout<<f[be][en]+w[be]+w[en];
        if(q>=1)cout<<endl;
    }
    return 0;
}
