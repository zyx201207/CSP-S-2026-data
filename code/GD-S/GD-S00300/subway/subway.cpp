#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+505;
int c,n,m,d,q,w[M],k[N];
int sz,ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;cin>>x>>y;
			ans+=y;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;	
		cout<<ans<<"\n";
	}
	return 0;
}

