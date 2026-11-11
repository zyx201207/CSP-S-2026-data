#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,ans;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=ans&a[i];
		if(a[i]==a[i-1]-1) ans=a[i];
	}
	cout<<ans;
	return 0;
 } 
