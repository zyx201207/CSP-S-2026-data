#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct node{
	int v,w;
};
vector<node> e[N];
int c,t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int a[n+5];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int w=abs(a[i]-a[j]);
				if(w<=d)
				{
				e[i].push_back({j,w});
				e[j].push_back({i,w}); 
				}
			}
		}
		int c=(a[2]-a[1])*2;
		if(d>=c)
		{
			cout<<n-3<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;	
} 
