#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int r,m,ans;
	cin>>r>>m;
	for(int i=1;i<=r;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+r,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}