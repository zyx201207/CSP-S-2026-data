#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e10;
ll c,n,m,d,q,x,r,y,sum;
vector <ll> w;
struct q()
{
	ll a1,a2,a3;
}e[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	cin>>k;
	for(ll i=1;i<=k;i++)
	{
		cin>>e[i].a1>>e[i].a3;
		e[i].a2=i;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>r>>y;
		cout<<w[r]+w[y]+e[r].a3+e[y].a3;
	} 
	fclose(stdin);
	fclose(stdout);
	
}
