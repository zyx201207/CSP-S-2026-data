#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int const M=3e5+5;
int a[N];
int s[M];
bool d[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool b=1;
	unordered_map<int,int> f;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]=i;//出现次数 
		if(i!=1&&a[i]<a[i-1])
			b=0;
	}
	if(b==1)
	{
		int l=1,r=n;
		for(int i=1;i<=m;i++)
		{
			r=n;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(a[mid]<=i)
					l=mid+1;
				else
					r=mid-1;
			}
			cout<<r<<" ";
		}
		return 0;
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<f[i]<<" ";
		}
		return 0;
	}
	for(int z=1;z<=n;z++)//第几局 
	{
		stack<int>q;
		memset(d,0,sizeof(d));
		for(int i=z;i<=n;i++)
		{
			if(d[a[i]]==0)
			{
				q.push(a[i]);
				d[a[i]]=1;
			}
			else
			{
				while(!q.empty()&&q.top()!=a[i])
				{
					d[q.top()]=0;
					q.pop();
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			s[i]+=d[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
