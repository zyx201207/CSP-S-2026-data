#include<bits/stdc++.h>
using namespace std;
const int N=305;
typedef long long ll;
ll n,d,__,_,mn,Inf;
ll a[N],s[N][N][N],s2[N][N];
int dfs(int x,int y,int cnt)
{
	if(s[x][y][cnt]!=-1) return s[x][y][cnt];
	if(x==y&&cnt==mn) return 1;
	int res=0;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]>d) break;
		res+=dfs(i,y,cnt+1);
	}
	return s[x][y][cnt]=res;
}
ll dfs2(int x,int y,int cnt)
{
	if(s2[x][y]!=Inf) return s2[x][y];
	if(x==y) return cnt;
	ll res=Inf;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]>d) break;
		res=min(res,dfs2(i,y,cnt+1ll));
	}
	return s2[x][y]=res;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&__,&_);
	while(_--)
	{
		memset(s,-1,sizeof(s));
		memset(s2,128,sizeof(128));
		Inf=s[1][1][1];
		int ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int l=1;l<n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				mn=dfs2(l,r,0);
				if(dfs(l,r,0)==2) cout<<l<<' '<<r<<'\n',ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
