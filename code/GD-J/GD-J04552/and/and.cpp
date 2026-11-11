#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
unsigned long long sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	sum=a[1];
	for(int i=2;i<=m;i++)
	{
		sum=(sum&a[i]);
	}
	cout<<sum<<endl;
	return 0;
 } 
