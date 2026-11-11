#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int n;
	int bin;
}a[200005];
int one(int n)
{
	int y=0;
	while(n!=0)
	{
		y+=n%2;
		n/=2;
	}
	return y;
}
bool cmp(node a,node b) 
{
	if(a.bin!=b.bin)
	{
		return a.bin>b.bin;
	}
	return a.n>b.n;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int maxn=-1;
	int op=1;
	
	cin>>a[1].n;
	a[1].bin=one(a[1].n);
	maxn=max(maxn,a[1].n);
	
	for(int i=2;i<=n;i++)
	{
		cin>>a[i].n;
		a[i].bin=one(a[i].n);
		maxn=max(maxn,a[i].n);
		if(a[i-1].n+1!=a[i].n)
		{
			op=0;
		}
	}
	
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(op==1)
	{
		cout<<a[n-m+1].n;
		return 0;
	}
	
	sort(a+1,a+1+n,cmp);
	int amns=a[1].n;
	for(int i=2;i<=m;i++)
	{
		amns=amns&a[i].n;
	}
	cout<<amns;
	return 0;
} 
