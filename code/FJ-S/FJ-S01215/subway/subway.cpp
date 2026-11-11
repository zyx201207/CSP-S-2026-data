#include <bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;

long long x,y,c,n,m,d,q,w[M],k[N];
vector<long long> a[N];
vector<long long> t[N];
vector<long long> num[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			num[i].push_back(0x3f3f3f3f);
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		long long xt,xa;
		for(int j=0;j<k[i];j++)
		{
			scanf("%lld%lld",&xa,&xt);
			a[i].push_back(xa),t[i].push_back(xt);
			for(int z=0;z<j;z++) num[a[i][z]][a[i][j]-a[i][z]]=t[i][z]+t[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int z=1;z<=m;z++)
			{
				if(i==j || j==z || i==z) continue;
				if(z>i && z>j && i<j) num[i][z-i]=min(num[i][z-i],num[i][j-i]+num[j][z-j]);
				else if(z>i && z>j && i>j) num[i][z-i]=min(num[i][z-i],num[j][i-j]+num[j][z-j]);
				else if(z>i && z<j) num[i][z-i]=min(num[i][z-i],num[i][j-i]+num[z][j-z]);
				else if(z>j && z<i) num[z][i-z]=min(num[z][i-z],num[j][i-j]+num[j][z-j]);
				else if(z<i && z<j && i<j) num[z][i-z]=min(num[z][i-z],num[i][j-i]+num[z][j-z]);
				else num[z][i-z]=min(num[z][i-z],num[j][i-j]+num[z][j-z]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(x<y) printf("%lld\n",num[x][y-x]+w[x]+w[y]);
		else printf("%lld\n",num[y][x-y]+w[x]+w[y]);
	}
	
	
	return 0;
}

