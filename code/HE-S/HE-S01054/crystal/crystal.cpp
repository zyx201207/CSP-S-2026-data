#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
int main()
{
	int sum=0;
	cin>>n>>m;
	int ans=0;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		sum+=a[i];
	}
	cout<<sum/b[3];
	return 0;
}
