#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int t;
long long ans;
struct node
{
	long long dis,num;
	bool operator<(const node& a) const
	{
		return a.dis>dis;
	}
};
priority_queue<node,vector<node>,less<node> >q;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		long long x;
		cin>>x;
		long long y=x;
		int k=1;
		while(x>=k)
		{
			a[k]++;
			q.push({y,k});
			x-=k;
			k*=2;
		} 
		t=max(t,k);
		if(x>0)
		{
			a[x]++;
			q.push({y,x});
		}
	} 
	while(t!=0)
	{
		if(a[t]>=m) break;
		t/=2;
	}
	for(int i=1;i<=m;i++) 
	{
		int k=q.top().dis;
		q.pop();
		ans=(ans&k);
	}
	cout<<ans;
	return 0;
}
