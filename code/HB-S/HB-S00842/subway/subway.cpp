#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    char c=getchar();
    int x=0,f=1;
    while (!isdigit(c))
    {
        if (c=='-') f=-f;
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}

void write(int a)
{
	if (a<0) putchar('-'),a=-a;
	if (a>=10) write(a/10);
	putchar((a%10)+48);
}

int in[500010];
vector<pair<int,int> > sta[500010];
int len[505][505];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=read(),m=read(),n=read(),d=read(),q=read();
    for (int i=1;i<=n;i++) in[i]=read();
    memset(len,0x3f,sizeof len);
    for (int i=1;i<=m;i++) len[i][i]=0;
    
    for (int i=1;i<=m;i++)
    {
        int k=read();
        for (int j=1;j<=k;j++)
        {
            int x=read(),w=read();
            for (auto r:sta[x]) len[i][r.first]=len[r.first][i]=min(len[i][r.first],r.second+w);
            sta[x].push_back({i,w});
        }
    }
    
    for (int k=1;k<=m;k++)
    {
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=m;j++) len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
        }
    }

    while (q--)
    {
        int u=read(),v=read();

        int ans=0x7f7f7f7f7f7f7f7f;

        for (auto i:sta[u])
        {
            for (auto j:sta[v]) ans=min(ans,i.second+j.second+len[i.first][j.first]);
        }
        write(ans+in[u]+in[v]);
        puts("");
    }

    return 0;
}
//15:38 AC T2
