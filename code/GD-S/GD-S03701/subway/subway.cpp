#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace B{
	int subway,n,m,d,q;
	ll w[500010];
	vector<ll>a[510];
	vector<ll>t[510];
	ll val[510][1010];
	ll arr[510][1010][1010];
	ll vis[1010][1010];
	ll l[100010],r[100010];
	int mark[100010];
	int main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		scanf("%d%d%d%d%d",&subway,&n,&m,&d,&q);
		for (int i=1;i<=m;i++)
		{
			scanf("%lld",&w[i]);
		}
		for (int i=1;i<=n;i++)
		{
			ll k;
			scanf("%lld",&k);
			a[i].push_back(k);
			t[i].push_back(k);
			for (int j=1;j<=k;j++)
			{
				ll x,y;
				scanf("%lld%lld",&x,&y);
				a[i].push_back(x);
				t[i].push_back(y);
			}
			for (int j=1;j<=k;j++)
			{
				val[i][a[i][j]]=t[i][j];
				if (j!=k)arr[i][a[i][j]][a[i][j+1]]=arr[i][a[i][j+1]][a[i][j]]=1;
				if (j!=1)arr[i][a[i][j]][a[i][j-1]]=arr[i][a[i][j-1]][a[i][j]]=1;
			}
		}
		for (int i=1;i<=q;i++)
		{
			scanf("%lld%lld",&l[i],&r[i]);
			mark[l[i]]=mark[r[i]]=1;
			ll mi=(1LL)*100000000*100000000;
			for (int j=1;j<=n;j++)
			{
				if (val[j][l[i]]!=0 && val[j][r[i]]!=0)
				{
					mi=min(mi,val[j][l[i]]+val[j][r[i]]);
				}
			}
			printf("%lld\n",w[l[i]]+w[r[i]]+mi);
		}
		return 0;
	}
};
int main(){
	return B::main();
}
