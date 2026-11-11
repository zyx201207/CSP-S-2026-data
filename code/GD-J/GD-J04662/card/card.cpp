#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,m;
int a[N],l[N],L[N];
int ans[N];
int lst[N];
int r[N];
int mx[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=m;i++) lst[i]=n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(L[a[i]]) l[i]=L[a[i]],r[L[a[i]]]=i;
		L[a[i]]=i;
	}
	
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		while(v.size()&&i>=r[v[v.size()-1]]) v.pop_back();
		if(v.size()) mx[i]=v[v.size()-1];
		if(r[i]) v.push_back(i);
//		cout<<mx[i]<<' ';
	}
//	cout<<'\n';
	
//	int mx=0;
	for(int i=n;i>=1;i--)
	{
//		if(i<=mx) mx=0;
		
//		cout<<i<<' '<<mx[i]<<'\n';
//		ans[a[i]]=max(ans[a[i]],i-mx);

		ans[a[i]]+=max(min(i,lst[a[i]])-mx[i],0ll);
		lst[a[i]]=min(lst[a[i]],mx[i]);
		
//		if(l[i])
//		{
//			mx=max(mx,l[i]);
//		}
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';

	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
