#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,INF=0x3f3f3f;
typedef long long ll;
int n,m;ll a[N];
struct Node
{
	ll b;
	int s,_n,_l;
};
Node c[N];
int main()//这道题明显用链表 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool B=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll btw=a[2]-a[1];
	for(int i=1;i<n;i++) if(a[i+1]-a[i]!=btw) B=0;
	if(B)
	{
		ll j=sqrt(2*m/btw);
		while((j+1)*j/2*btw<=m) j++;
		cout<<j-1;
	}
	else
	{
	sort(a+1,a+n+1);
	int idx=1;
	c[1].s=1,c[1]._l=-1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) c[idx].s++;
		else c[idx].b=a[i]-a[i-1] , c[idx++]._n=idx , c[idx].s=1 , c[idx]._l=idx-1;
	}
	while(m)
	{
		ll minn=(ll)INF*INF;int mink=-1;
		for(int i=1;i<idx;i++)
		{
			if(minn>c[i].b*c[i].s) mink=i;
			minn=min(minn,c[i].b*c[i].s);
		}
		if(m<minn)
		{
		int num=m/c[mink].b;
		m-=num;
		c[c[mink]._n].s+=num;
		c[c[mink]._l].b+=c[mink].b; 
		c[mink].s-=num;
		c[mink].b=(ll)INF*INF;
		}
		else
		{
		m-=minn;
		c[c[mink]._n].s+=c[mink].s;
		c[c[mink]._l].b+=c[mink].b; 
		c[c[mink]._n]._l=c[mink]._l;
		c[c[mink]._l]._n=c[mink]._n;
		c[mink].b=(ll)INF*INF;
		}
	}
	int maxn=-1;
	for(int i=1;i<=idx;i++)
	{
		maxn=max(maxn,c[i].s);
	}
	cout<<maxn;
	}
	return 0;
 } 
