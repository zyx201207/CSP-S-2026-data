#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		ans=max(ans,a);
	}
	cout<<ans;
	return 0;
}
