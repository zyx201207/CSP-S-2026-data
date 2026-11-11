#include<bits/stdc++.h>
using namespace std;
#define int long long
const int all=(1ll<<30)-1;
int n,m;
int ans=0;
int a[200005];
bool vis[200005];
bool cmp(int x,int y){return x>y;}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int k=30;k>=0;k--)
	{
		vector<int> v;
		for(int i=1;i<=n;i++)
			if((a[i]>>k)&1)v.push_back(a[i]);
		sort(v.begin(),v.end(),cmp);
		int u=all,xm=m;
		for(int i=0;i<v.size() && xm;i++,xm--)u=u&v[i];
		if(xm==0)ans=max(ans,u);
	}
	int f=all;
	for(int i=1;i<=m;i++)f=(f&a[i]);
	cout<<max(ans,f);
	return 0;
}
