#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int max1=0,n,a[200010],m,b=1,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i<=m;i--)
		sum*=i;
	for(int i=n-m;i>=1;i++)
		sum/=i;
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b=b&a[j];
			if(b>max1) 
				b=max1;
		}
	}
	cout<<max1<<endl;
	return 0;
}
