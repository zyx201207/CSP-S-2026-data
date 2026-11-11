#include<bits/stdc++.h>
#define ll long long
int c,n,m,d,q,w[500001],k;
using namespace std;
struct subway{
	int k,t[500001];
}a[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++)
		{
			cin>>k;
			cin>>a[i].t[k];
		}
	}
	return 0;
}
