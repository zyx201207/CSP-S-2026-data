#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long mi[40];
long long n,m,ans=0;
queue<long long> q;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push(a[i]);
	}
	mi[0]=1;
	for(int i=1;i<=31;i++)
	{
		mi[i]=mi[i-1]*2;
		//cout<<mi[i]<<endl;
	}
	for(int j=30;j>=0;j--)
	{
		long long cnt=0,len=q.size();
		for(int i=1;i<=len;i++)
		{
			long long now=q.front();
			q.pop();
			if((now&mi[j])!=0)
			{
				cnt++;
			}
			q.push(now);
		}
		if(cnt<m)
		{
			continue;
		}
		ans+=mi[j];
		for(int i=1;i<=len;i++)
		{
			long long now=q.front();
			q.pop();
			if((now&mi[j])!=0)
			{
				q.push(now);
			}
		}
	}
	cout<<ans;
	return 0;
}
