#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int data,cnt;
}a[200005];
int n,m,ans,k;
bool cmp(node x,node y)
{
	if(x.cnt!=y.cnt)return x.cnt>y.cnt;
	return x.data>y.data;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		k=1;
		cin>>x;
		a[i].data=x;
		a[i].cnt=0;
		while(x>0)
		{
			x-=k;
			a[i].cnt++;
			k*=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].data;
	for(int i=2;i<=m;i++)
		ans&=a[i].data;
	cout<<ans;
	return 0;
}
