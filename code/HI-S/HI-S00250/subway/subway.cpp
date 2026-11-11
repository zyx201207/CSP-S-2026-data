#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,x,y;
struct N
{
	int a,t;
}xl[505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >>d >>q;
	for(int i=1;i<=m;i++)cin >>w[i];
	for(int i=1;i<=n;i++)
	{
		cin >> k;
		for(int j=1;j<=k;j++)cin >> xl[j].a >>xl[j].t;
	}
	for(int i=1;i<=q;i++)
	{
		cin >>x >>y;
		
	 } 
	return 0;
}
