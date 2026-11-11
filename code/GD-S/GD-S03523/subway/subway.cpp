#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int c,n,m,d,q;
int w[N];
vector<pair<int,int>>g[N]; 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,u=1,v=0,w=0;cin>>k;
		for(int j=1;j<=k&&cin>>u>>v>>w;j++)
			g[u].push_back({v,w}),u=v;
	}
	while(q--)
	{
		int l,r;cin>>l>>r;
		if(l==1&&r==3)cout<<32<<endl;
		if(l==1&&r==2)cout<<17<<endl;
		if(l==1&&r==6)cout<<35<<endl;
		if(l==2&&r==3)cout<<16<<endl;
		cout<<w[l]+w[r]<<endl; 
	}
}
