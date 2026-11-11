#include<iostream>
#include<algorithm>
using namespace std;
const long long MX=2e5+5,inf=~(1<<31);
long long n,m,a[MX];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(n==m)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+1+n);
		long long ans=a[n];
		for(int i=1;i<m;i++)
		{
			ans=ans&a[n-i];
		}
		cout<<ans;
	}
	
	return 0;
} 
