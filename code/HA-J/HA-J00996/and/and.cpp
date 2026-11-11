#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	do
	{
		long long t=a[1];
		for(int i=2;i<=m;i++)
		{
			t&=a[i];
		}
		ans=max(ans,t);
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
	return 0;
}
