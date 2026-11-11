#include<bits/stdc++.h>
using namespace std;
int a[200200]={},b[200200]={};
int n,m;
int f(int x,int p,int q)
{
	if(x==0)
	{
		return p;
	}
	int sum=0;
	for(int i=q;i<=n-x+1;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			int ans=f(x-1,(a[i]&p),i+1);
			sum=max(sum,ans);
			b[i]=0;
		}
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<f(m,INT_MAX,1);
	return 0;
}
