#include<bits/stdc++.h>
using namespace std;
int s[200005], a[200005],ans[200005];
vector<pair<int,int>> v;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		s[i]=a[i]&s[i-1];
		cout<<a[i]<<endl;
	}
	for(int i=1; i<=n; i++)
	{
		s[i]=a[i];
		for(int j=i+1; j<=i+m; j++)
		{
			s[i]=s[i-1]&a[j];
		}
		ans[i]=s[i+m]-s[i];
	}
	sort(ans+1,ans+n+1,greater<>());
	cout<<ans[1];
	return 0;
}
