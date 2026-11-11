//subway

#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,K,s,e,w[500001],ans=0;
struct sub
{
	int t,a;
}k[501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>K;
		for(int j=1;j<=K;j++)
		{
			cin>>k[j].a>>k[j].t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s>>e;
		ans+=w[s]+w[e]+k[s].t+k[e].t;
		cout<<ans<<"\n";
	}
}
