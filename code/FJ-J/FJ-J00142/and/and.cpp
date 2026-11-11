#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt1,cnt0 = 64,cnt;
int a[200010];
struct node
{
	int  shu1;
	int qian0;
	int  zhi;
}b[200010];
int ercnt(int a)
{
	if(a == 0) return 0;
	while(a/2!=0)
	{
		if(a%2 == 1) cnt1++;
		a/=2;
	}
	return cnt1+1;
}
int erqian0(int a)
{
	if(a == 0) return cnt0;
	while(a/2!=0)
	{
		cnt++;
		a/=2;
	}
	cnt++;
	return cnt0-cnt;
}
bool cmp(node x,node y)
{
	if(x.shu1 != y.shu1) return x.shu1 > y.shu1;
	else
	{
		return x.qian0 < y.qian0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++)
	{ 
		b[i].shu1 = ercnt(a[i]);
		b[i].qian0 = erqian0(a[i]);
		b[i].zhi = a[i];
		cnt1 = 0;
		cnt = 0;
		cnt0 = 64;
	}
	sort(b+1,b+n+1,cmp);
	long long ans = b[1].zhi;
	for(int i = 2;i<=m;i++)
	{
		ans = ans & b[i].zhi;
	}
	cout<<ans;
	return 0;
}
