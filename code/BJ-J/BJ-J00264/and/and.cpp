#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,c;
};
bool cmp(node x,node y)// 对于正常的数据，按照二进制位数排序
{
	if(x.c!=y.c) return x.c>y.c;
	return x.v>y.v;
}
bool cmphyw(node x,node y)//对于特殊性质B这种伪人数据，按照数组大小排序hyw 
{
	return x.v>y.v;
}
int hyw(int x)
{
	int cnt=0;
	while(x)
	{
		x-=x&-x;
		cnt++;
	}
	return cnt;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	node a[n+1]={};
	for(int i=1;i<=n;i++) cin>>a[i].v;
	for(int i=1;i<=n;i++)
	{
		a[i].c=hyw(a[i].v);
	}
	bool hywflag=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i].v!=i-1)
		{
			hywflag=false;
			break;
		}
	}
	if(!hywflag) sort(a+1,a+n+1,cmp);
	else sort(a+1,a+n+1,cmphyw);
	int ans=a[1].v;
	for(int i=2;i<=m;i++)
	{
		ans&=a[i].v;
	}
	cout<<ans;
	return 0;
}
