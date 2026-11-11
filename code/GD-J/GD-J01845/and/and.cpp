#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int mx,mn;
	cin>>mn;
	mx=mn;
	int a;
	for(int i=2;i<=n;i++) 
	{
		cin>>a;
		mn=mn&a;
		mx=max(mx,a);
	}
	mx=max(mx,mn);
	cout<<mx;
	return 0;
 }
