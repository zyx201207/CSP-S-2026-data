#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long cha[500005],plu[500005];
long long l,r,sum,sum2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
	}
	int ans=0;
	for(int i=1,j=1;j<=n;j++)
	{
		sum=sum+(j-i)*cha[j];
		ans=max(ans,j-i);
		while(sum>m)
		sum=sum-(a[j]-a[i]),i++;
	}
	cout<<ans;
	return 0;
}
