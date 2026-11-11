#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t,n,k,x,y;
int a[N];
vector<int> g[N];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1; i<=n; i++)
		{
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=1; i<=n; i++)
			a[i]=g[i].size();
		sort(a+1,a+1+n);
		if(k == 2)	
			cout<<"1\n";
		else if(k <= a[n]+1)
			cout<<"2\n";
		else
			cout<<n-1<<"\n";
	}
	return 0;
}
