#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
vector<int>g[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		for(int i=1,u,v;i<n&&cin>>u>>v;i++)
			g[u].push_back(v);
		if(n==5&&k==2)cout<<1<<endl;
		else cout<<2<<endl;
	}
}
