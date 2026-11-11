#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
bool bst;
int c,T,n,cnt[N],to[N][22],q[N],lst[N],f[N][22][2];
long long ans,d,s[N][22],a[N];
bool bed;
void solve()
{
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],q[i]=lst[i]=f[i][0][0]=f[i][0][1]=s[i][0]=cnt[i]=0;
	for(int i=n;i;--i)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]-a[i]<=d)to[i][0]=mid,l=mid+1;
			else r=mid-1;
		}
		lst[to[i][0]]++;
		for(int j=1;j<=21;j++)to[i][j]=to[to[i][j-1]][j-1];
	}
	q[0]=0;
	for(int i=1,l=1,r=0;i<=n;i++)
	{
		while(l<=r&&q[l]<=i)cnt[q[l]]--,l++;
		s[i][0]=cnt[to[i][0]];
		if(l<=r)
		{
			f[i][0][0]=to[i][0]-q[r];
			if(l<=r-1)f[i][0][1]=q[r]-q[r-1];
			else f[i][0][1]=q[r]-i;
		}
		else f[i][0][0]=to[i][0]-i;
		q[++r]=to[i][0],cnt[q[r]]++;
	}
	for(int i=n;i;--i)for(int j=1;j<=21;j++)
	{
		s[i][j]=s[i][j-1]+s[to[i][j-1]][j-1];
		f[i][j][0]=f[i][j-1][0]+f[to[i][j-1]][j-1][0];
		f[i][j][1]=f[i][j-1][1]+f[to[i][j-1]][j-1][1];
	}
	for(int i=1;i<=n;i++)
	{
		int x=i,y=i;long long add=0,now=0;
		for(int j=21;~j;--j)if(now+s[y][j]<=0)now+=s[y][j],add+=f[y][j][1],y=to[y][j];
		add+=f[y][0][1];
		ans+=1ll*lst[i]*add;
		x=y,add=0;
		for(int j=21;~j;--j)if(now+s[y][j]<=1)now+=s[y][j],add+=f[y][j][0],y=to[y][j];
		add+=f[y][0][0];
		ans+=1ll*lst[i]*add;
	}
	cout<<ans<<'\n';
}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cerr<<(&bst-&bed)/1024/1024<<'\n';
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>c>>T;while(T--)solve();
	return 0;
}
