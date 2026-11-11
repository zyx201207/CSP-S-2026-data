#include<bits/stdc++.h>
using namespace std;
int const c=2e5;
int a[c];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,i,max1=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,a.begin());
	for(int i=1;i<=m;i++)
	{
		max1=min(a[i],a[i+1]);
	}
	cout<<max1;
	return 0;
}
