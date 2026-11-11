#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct node
{
	int x,len;
}a[200010];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
int n,m;
int v[200010][35];
int sum[40];//某一位为 1的数的个数
set<int> num[40];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		int t=a[i].x;
		int cnt=0;
		while(t)
		{
			t/=2;
			cnt++;
		}
		a[i].len=cnt;
	}
	sort(a+1,a+n+1,cmp);
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		int t=a[i].x;
		int cnt=0;
		while(t)
		{
			v[i][++cnt]=t%2;
			t/=2;
		}
		mx=max(mx,cnt);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=33;j++)
		{
			if(v[i][j]==1)
			{
				sum[j]++;
				num[j].insert(i);
			}
		}
	}
	while(sum[mx]<m&&mx>=1)mx--;
	if(mx<1)
	{
		cout<<0;
		return 0;
	}
	set<int> ans;
	for(auto x:num[mx])
		ans.insert(x);
	while(mx>1)
	{
		
		mx--;
		set<int> t;
		for(auto x:num[mx])
			t.insert(x);
		int lt=0;
		for(auto x:t)
		{
			if(ans.count(x))lt++;
		}
		if(lt<m)continue;
		else
		{
			for(auto x:t)
			{
				if(!ans.count(x))t.erase(x);
			}
			ans.clear();
				
			for(auto x:t)
			{	
//				cout<<x<<' ';
				ans.insert(x);
			} 
//			cout<<endl;
		}
	}
	int ans1=-1;
	for(int x:ans)
	{
//		cout<<x<<' ';
		if(ans1==-1)
		{
			ans1=a[x].x;
			continue;
		}
		ans1&=a[x].x;
	}
	cout<<ans1;
//	for(auto x:ans)cout<<x<<' ';
	return 0;
}
/*
4 3
3
15
12
15

*/  