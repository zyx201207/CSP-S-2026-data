#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,kk,y,l,r,z,dp[5000][5000],minn,s;
struct lzy
{
	int x;
	int z;
}a[500010];
void ymz(int k)
{
	if(k==r)
	{
		if(s<minn)
		{
			minn=s;
		}
		return;
	}
	for(int i=1;i<=510;i++)
	{
		if(dp[k][i]==1)
		{
			dp[k][i]=0;
			dp[i][k]=0;
			s=s+a[i].z;
			ymz(i);
			s=s-a[i].z;
			dp[k][i]=1;
			dp[i][k]=1;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>kk>>y;
			a[kk].z=a[kk].z+y;
			//cout<<kk<<" "<<a[kk].z<<" ";
			if(j>1)
			{
				dp[z][kk]=1;
				dp[kk][z]=1;
			}
			z=kk;
		}
	}
	for(int i=1;i<=q;i++)
	{
		minn=INT_MAX;
		cin>>l>>r;
		s=a[l].x+a[r].x;
		ymz(l);
		cout<<minn;
	}
	return 0;
} 
