#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll printnumber[105];
inline ll in()
{
	ll ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=getchar();
	while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
	return ans*f;
}
inline void out(ll x,char y)
{
	ll tot=0;
	if(x<0)putchar('-'),x=-x;
	do
	{
		printnumber[++tot]=x%10;
		x/=10;
	}while(x);
	while(tot)putchar(printnumber[tot--]+'0');
	putchar(y);
	return ;
}
ll c,n,m,d,q,w[500005],dis[505][505];
vector<pair<ll,ll> > cnt[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),q=in();
	for(int i=1;i<=m;i++)w[i]=in();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i!=j?1000000000000000000ll:0ll);
	for(int i=1;i<=n;i++)
	{
		ll k=in(),ai=0,ti=0;
		while(k--)
		{
			ai=in(),ti=in();
			ll len=cnt[ai].size();
			for(int j=0;j<len;j++)dis[i][cnt[ai][j].first]=dis[cnt[ai][j].first][i]=min(dis[i][cnt[ai][j].first],ti+cnt[ai][j].second);
			cnt[ai].push_back({i,ti});
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	}
	while(q--)
	{
		ll x=in(),y=in(),mi=1e18;
		if(x==y)
		{
			out(0,'\n');
			continue;
		}
		ll lenx=cnt[x].size(),leny=cnt[y].size();
		for(int i=0;i<lenx;i++)for(int j=0;j<leny;j++)
		{
			mi=min(mi,dis[cnt[x][i].first][cnt[y][j].first]+cnt[x][i].second+cnt[y][j].second);
		}
		out(mi+w[x]+w[y],'\n');
	}
	return 0;
}
