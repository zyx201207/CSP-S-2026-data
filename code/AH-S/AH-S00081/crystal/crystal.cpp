#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],s[500005];
queue <long long> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=a[i]-a[i-1],s[i]=s[i-1]+c[i];
	long long sum=0,ma=0;
	for(int i=2;i<=n;i++)
	{
		q.push(i);
		sum+=c[i]*q.size();
		while(sum>m) 
		{
			int u=q.front();
			q.pop();
			sum-=s[i]-s[u-1];
		}
		ma=max(ma,(long long)q.size());
	}
	cout<<ma+1;
	return 0;
}
