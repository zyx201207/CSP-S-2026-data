#include<bits/stdc++.h>
using namespace std;
long long a[2000000],n,d,cnt[2000000],c,t;
queue<pair<long long,long long>> q;
int find(int x)
{
	int l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]<x)
			l=mid;
		else
			r=mid-1;
	}
	return 90909000;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int sum=0,f=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i>=1;i--)
		{
			q.push({a[i],i});
			while(!q.empty())
			{
				int k=q.front().first;
				q.pop();
				if(q.front().second==1)
				{
					f=1;
					cnt[q.front().second]++;
				}
				for(int j=d;j>=1;j--)
				{
					int o=find(k-j);
					if(o>=90909000)
						continue;
					else
					{
						if(f==0)
							q.push({k-j,o});
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(cnt[i]==2)
				sum++;
		cout<<sum<<endl;
	}
	return 0;
}
