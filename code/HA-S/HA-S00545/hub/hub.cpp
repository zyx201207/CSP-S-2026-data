#include <bits/stdc++.h>
using namespace std;
int c,t,a[1000005],n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if (c==13||c==14)
	{
		while (t--)
		{
			cin>>n>>k;
			cout<<ceil(((n-1)/2+1-k)/4)+1<<"\n";
		}
	}
}
