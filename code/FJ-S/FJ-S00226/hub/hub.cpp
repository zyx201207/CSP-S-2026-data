#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,l1,l2;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>l1>>l2;
		n=n/2+1;
		n=(n+3)/4;
		cout<<n<<'\n';
	}
	return 0;
}
