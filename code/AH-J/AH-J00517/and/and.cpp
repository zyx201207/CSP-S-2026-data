#include <bits/stdc++.h>
using namespace std;
long long n,m,e;
long long a[1000005];
stack<long long>s;
long long shuai[1000005]={1},shuai1[1000005];
long long maxn=-99999999999;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=0)
		{
			s.push(a[i]%2);
			a[i]/=2;
		}
		while(!s.empty())
		{
			shuai[i]*=10;
			shuai[i]+=s.top();
			s.pop();
		}
	}
	for(int i=1;i<=n;i++)
	{
		shuai1[i]=shuai[i];
		int x=i;
		for(int j=1;j<=m;j++)
		{
			shuai1[i]+=shuai[i]+shuai[x]-1111;
			shuai1[i]-=1111;
			x++;
		}
		maxn=max(maxn,shuai1[i]);
	}
	cout<<maxn;
	return 0;
}
