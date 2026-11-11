#include<bits/stdc++.h>
#define int long long
#define il inline
#define pii pair<int,int>

using namespace std;
const int maxn=2e5+5,maxl=32;
int n,m,sm0,sm1,mxl;
bool vis[maxn],a[maxn][maxl],ans[maxl];
il int read()
{
	int res,f=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')
		if(ch=='-')
			f=-1;
	res=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res*f;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=0;
		while(x)
		{
			a[i][++y]=x%2;
			x>>=1;
		}		
		mxl=max(mxl,y);
	}
	for(int i=mxl;i;i--)
	{
		sm0=sm1=0;
		for(int j=1;j<=n;j++)
			if(!vis[j])
				if(a[j][i])
					sm1++;
				else
					sm0++;
		if(sm1>=m)
		{
			ans[i]=1;
			for(int j=1;j<=n;j++)
				if(!a[j][i])
					vis[j]=1;
		} 
		else
			ans[i]=0;
	}
	int x=0,y=1,z=1;
	while(z<=mxl)
	{
		x+=ans[z++]*y;
		y<<=1;
	}
	printf("%lld\n",x);
	return 0;
}

