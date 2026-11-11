#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=5005;
//ll c,n,m,d,q,w[MAX],a[MAX][MAX],t[MAX][MAX],r[MAX][2],sub[MAX][3][MAX],ans;
ll c,n,m,d,q,w[MAX],a[MAX][MAX],t[MAX][MAX],r[MAX][2],ans;
//void build(ll wit,ll to)
//{
//	sub[wit]
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll K;
		cin>>K; 
		for(ll j=1;j<=K;j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(ll i=1;i<=q;i++)
		cin>>r[i][0]>>r[i][1];
	for(ll xxx=1;xxx<q;xxx++)
	{
		ans=w[r[xxx][0]]+w[r[xxx][1]];
		cout<<ans<<endl;
	}
	return 0;
}
/* 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
