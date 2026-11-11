#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx=-1;
long long dfs(int n1,int m1,long long sum)
{
	long long mx1=-1;
	if(m1==m)
	{
		return sum;
	}
	for(int i=n1+1;i<=n;i++)
	{
		mx1=max(dfs(i,m1+1,sum&a[i]),mx1);
	}
	return mx1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);		
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		long long sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		long long sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i+m-1<=n;i++)
	{
		mx=max(dfs(i,1,a[i]),mx);
	}
	cout<<mx;
	return 0;
}
