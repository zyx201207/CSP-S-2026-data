#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510,M=1e6+10;
ll C,n,m,d,q,w[M],k,x,y,fa[N],lll;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		ll a[N]={0},t[N]={0};
		for(int j=1;j<=k*2;j++)
		{
			cin>>a[j]>>t[j];
		}
		lll=t[1];
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]+lll*2<<'\n';
	}
	return 0;
}
/*
我就是个gay！！！做不出来我不配活着了 
*/
