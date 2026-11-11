#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,m,i,x,y;
		cin>>n>>k;
		m=n/2;
		for(i=1;i<n;i++)
			cin>>x>>y;
		cout<<(m-(m+k)/2+2)/2<<'\n';
	}
	return 0;
}
