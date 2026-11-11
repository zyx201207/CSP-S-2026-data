#include<bits/stdc++.h>
using namespace std;
int n,m,b[200005];
long long ans;
struct node{
	long long k;
	int l;
}a[200005];
bool cmp(node x,node y)
{
	if(x.l==y.l)
	return x.k>y.k;
	return x.l>y.l;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		int x=a[i].k;
		while(x)
		{
			x-=x&-x;
			a[i].l++;
		}
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].k;
	for(int i=2;i<=m;i++)
	{
		ans&=a[i].k;
	}
	cout<<ans;
	return 0;
}
