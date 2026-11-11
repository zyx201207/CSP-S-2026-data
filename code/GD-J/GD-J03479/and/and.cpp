#include<bits/stdc++.h>
using namespace std;
int n,m,maxx,a;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		maxx=max(maxx,a);
	}
	cout<<maxx;
	return 0;
}
