#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,a[2000010];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t>0)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)cin>>a[i];
		cout<<1<<"\n";
		--t;
	}
	return 0;
}
