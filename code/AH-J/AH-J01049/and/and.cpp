#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
signed main()
{
	//freopen("and3.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int max1=a[i];
		for(int j=i+1;j+k-1<=n;j++)
		{
			for(int k=j;k<=j+k-1;k++) max1&=a[k];
			sum=max(sum,max1);
		}
	}
	cout<<sum;
	return 0;
}
