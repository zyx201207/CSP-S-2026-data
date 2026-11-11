#include<bits/stdc++.h>
#include<string>
using namespace std;
long long i,n,m,ans,a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	ans=a[n];
	cout<<ans;
	return 0;
} 
