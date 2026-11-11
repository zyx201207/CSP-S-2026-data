#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int a=0;int b=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if (c=='-')
        {
            b=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
    }
    return a*b;
}
int cnt;
int c,n,m,d,p;
int v[500005];
int head[1000005];

struct edg
{
    int to;int val;int nxt;
}t[500005];
edg add(int u,int v,int dis)
{
    cnt++;
    t[cnt].to=v;
    t[cnt].val=dis;
    t[cnt].nxt=head[u];
    head[u]=cnt;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        v[i]=read();
    }
    return 0;
}