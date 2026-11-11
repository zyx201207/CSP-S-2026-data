#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],b[500005];
long long int ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		long long int sum=0,com=1;
		for(long long int j=i;j<n;j++)
		{
			sum+=b[j]*com;
			if(sum>m)
			{
				ans=max(ans,com);
				break;
			}
			++com;
		}
	}
	cout<<ans;
	return 0;
}
