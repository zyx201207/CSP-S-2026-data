#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	cin>>ans;
	for(int i=2;i<=n;i++)
	{
		int t;
		cin>>t;
		ans&=t;
	}
	cout<<ans;
}

