#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<"\n";
#else
#define debug(x)
#endif
#define ll long long
#define PII pair<int,int>
#define vct vector
#define pb push_back
#define int long long

#ifdef LOCAL
bool ____st;
#endif
int n,m,top,a[500010],nxt[500010],ans[300010],lst[300010],ned[500010],tmp[500010],d[500010];
struct node
{
	int pos,val;
}st[500010];
#ifdef LOCAL
bool ____ed;
#endif

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ed-&____st)/(1024*1024)<<"Mib\n";
	double ____ST=clock();
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lst[a[i]]=i;
	}
	int fst=1;
	for(int i=1;i<=n;i++)
	{
		while(fst<=n&&(fst<i||lst[a[fst]]==fst))
		{
			fst++;
		}
		tmp[i]=fst;
		nxt[i]=fst==n+1?n+1:lst[a[fst]]+1;
//		debug(tmp[i]);
//		debug(nxt[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ned[i]++; 
		ned[nxt[i]]+=ned[i];
//		debug(ned[i]);
	}
	for(int i=1;i<=n;i++)
	{
		d[i]+=ned[i];
		d[tmp[i]+1]-=ned[i];
	}
	for(int i=1;i<=n;i++)
	{
		d[i]+=d[i-1];
		ans[a[i]]+=d[i];
//		debug(d[i]); 
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
#ifdef LOCAL
	double ____ED=clock();
	cerr<<'\n'<<(____ED-____ST)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
// There are people dying
