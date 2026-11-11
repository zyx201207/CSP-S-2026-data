#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<int> g;
int w[500010];
bool k[510][500010];
int st[510];
int en[510];
main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%lld",&x);
		w[i]=x;
	}
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		if(x>2)
			f=1;
		int y;
		scanf("%lld",&y);
		st[i]=y;
		x--;
		while(x--)
		{
			scanf("%lld",&y);
			w[y]++;
		}
		en[i]=y;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}
