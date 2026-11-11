#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cout<<a[1]+a[2];
	return 0;
}
