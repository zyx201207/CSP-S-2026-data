#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[200010],k[40];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		for(int j=1;x;j++)
			k[j]+=(x%2),x/=2;
	}
	for(int i=30;i;i--)
	{
		if(k[i]>=m)
		{
			cout<<i<<"-----------";
			ans+=(1<<(i-1)),m=k[i];
		}
	}
	cout<<ans;
	return 0;
}
//4 2
//3 15 12 12

