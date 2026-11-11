#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k,a,b,ans;
int w[500010],e[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>e[j];
		}	
	}
	while(q--)
	{
		ans=0;
		cin>>a>>b;
		ans=w[a]+w[b]+abs(b-a)*2*e[1];
		cout<<ans<<endl;
	}
}