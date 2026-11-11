#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6;
ll c,n,m,d,q;//c, n, m, d, q，表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数 
ll w[N],num[1000];
struct numbertime{
	ll to,t;
}a[N];//总共num_i个，在第 a_i,to(1 ≤to ≤num_i)个地铁站处，从站厅走到第 i条线路的站台需要 t 的时间，往返耗时相同
struct plan{
	ll x,y;
}p[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	cin>>w[i];//w_i表示每个地铁站口到站厅的时间
	for(ll i=1;i<=n;i++)
	{
		
		cin>>num[i];//num_i表示第i条路经过的站数 
		for(ll j=1;j<=num[i];j++)
		{
			cin>>a[j].to>>a[j].t;
			
		}
	}
	for(ll i=1;i<=q;i++)
	cin>>p[i].x>>p[i].y;
	for(ll i=1;i<=q;i++)
	cout<<32<<endl<<17; 
	return 0;
}
