#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int eps=0,p=n;
		while(p>10)
		{
			eps++;
			p/=10;
		}
		if(p>=5)
			eps++;
		if(k<=n/2+1)
			cout<<ceil(n/k*1.0)+eps<<'\n';
		else
			cout<<floor(n/k*1.0)-eps<<'\n';
	}
	return 0;
}
