#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long n,m,a[500005],ans=-1;
long long l,r,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<'\n';
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<'#'<<i<<'\n';
	}
	//cout<<'$';
	sort(a+1,a+n+1);
	//cout<<'*';
	for(int i=1;i<=n;i++)
	{
		l=i;
		sum=0;
		while(1)
		{
			if(l<1) break;
			if(sum+a[i]-a[l]<=m)
			{
				sum=sum+a[i]-a[l];
				l--;
			} 
			else break;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
