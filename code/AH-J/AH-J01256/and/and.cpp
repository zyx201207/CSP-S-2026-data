#include<bits/stdc++.h>
using namespace std;
long long int a[200010],dp[200010];
bool f[200010];
long long int an(long long int a,long long int b)
{
	long long int j=0;
	while(a>=1&&b>=1)
	{
		if(a%2==1&&b%2==1)
		{
			j=j*2+1;
		}else{
			j=j*2;
		}
		a/=2;
		b/=2;
	}
	return j;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m,am=0,im;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		am=max(am,a[i]);
		im=i;
	}
	for(int i=1;i<=m;i++)
	{
		dp[i]=-1;
	}
	dp[1]=am;
	f[im]=1;
	for(int k=2;k<=m;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(!f[i])
			{
				dp[k]=max(dp[k],an(dp[k-1],a[i]));
				f[i]=1;
			}
		}
	}
	cout<<dp[m];
	return 0;
	
}
