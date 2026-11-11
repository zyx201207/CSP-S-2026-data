#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x;
	cin>>n>>m;
	int a[1005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		x=max(a[i],a[i+1]);
	} 
	cout<<x;
	return 0;
}
