#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(int &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<48||ch>57)f=(ch=='-')?-f:f,ch=getchar();
    while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
    x*=f;
}
inline void readl(ll &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<48||ch>57)f=(ch=='-')?-f:f,ch=getchar();
    while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
    x*=f;
}
inline void readll(__int128 &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<48||ch>57)f=(ch=='-')?-f:f,ch=getchar();
    while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
    x*=f;
}
const int N=2e6+5;
int c,_,n,dis[N],ji[N],vis[N];
ll ans;
__int128 d,a[N];
vector<int>e[N];
void bfs(int s)
{
    for(int i=1;i<=n;i++)dis[i]=ji[i]=0;
    queue<pair<int,int>>q;
    q.push({s,0}),dis[s]=1;
    while(!q.empty())
    {
        int u=q.front().first,w=q.front().second;q.pop();
        for(auto v:e[u])
        {
            if(dis[v]==0)
                q.push({v,w+1}),dis[v]=w+1,ji[v]=1;
            else if(w+1==dis[v])ji[v]++;
        }
    }
    for(int i=s;i<=n;i++)if(ji[i]==2)ans++;
}
void out(__int128 x)
{
	if(x>9)out(x/10);
	putchar(x%10+48);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(c),read(_);
    if(c==11||c==12)
    {
        while(_--)
        {
            read(n),readll(d);
            for(int i=1;i<=n;i++)
                readll(a[i]);
            __int128 k=a[2]-a[1];
            d/=k;
            if(d<2)
            {
				cout<<0<<'\n';
		        continue;
			}
			out(max(__int128(0),(__int128)n-2*d+1)),putchar('\n');
        }
        return 0;
    }
    while(_--)
    {
        read(n),readll(d);
        for(int i=1;i<=n;i++)
            readll(a[i]),e[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
				if((i<j&&a[j]-a[i]<=d)||(i>j&&a[i]-a[j]<=d))
					e[i].push_back(j);
        for(int i=1;i<=n;i++)bfs(i);
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
