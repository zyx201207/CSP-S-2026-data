#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long ans=INT_MAX;
long long a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>n-m;i--)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
