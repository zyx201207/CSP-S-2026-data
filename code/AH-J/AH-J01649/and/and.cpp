#include<bits/stdc++.h>
using  namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(1)
		{
			n/=2;
			if(n==0)
			cout<<i-1;
		}
	}
	return 0;
}
