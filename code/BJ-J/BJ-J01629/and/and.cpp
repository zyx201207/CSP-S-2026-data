#include<bits/stdc++.h>
using namespace std;
int n,m,mx,ct,a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
	return 0;
}
