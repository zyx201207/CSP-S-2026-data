#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
char sum1[2000005];
char sum2[2000005];
long long ans;
int main()
{
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	cout<<sum;
	int x=1,y=0;
	for(int i=1;i<=sum/2;i++)
	{
		sum1[i]=c[x];
		y++;
		if(y==a[x])
		{
			x++;
			y=0;
		}
	}
	x=n,y=0;
	for(int i=1;i<=sum/2;i++)
	{
		sum2[i]=c[x];
		y++;
		if(y==a[x])
		{
			x--;
			y=0;
		}
	}
	for(int i=1;i<=sum/2;i++)
	{
		cout<<sum1[i]<<" "<<sum2[i]<<"\n";
		if(sum1[i]!=sum2[i])ans++;
	}
	cout<<ans;
	return 0;
}
