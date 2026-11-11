#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long int a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,c=1,ans=0;
	cin>>n>>m;
	int d=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]+m>=a[i+1])
		{
			b[c]=a[i];
			c++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=d;j++)
		{
			ans+=(b[d]-b[j]);
		}
		if(ans<=m)
		{
			break;
		}
			else d--;
			ans=0;
	}
	cout<<d<<endl;
	return 0;
}
