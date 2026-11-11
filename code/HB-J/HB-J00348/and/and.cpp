#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005],b[200005];
int ten(int x)
{
	int cnt=0,res=0;
	while(x!=0)
	{
		int num=1;
		int tx=x%10;
		x/=10;
		for(int i=1;i<=cnt;i++) num*=tx;
		res+=num;
	}
	return res;
}
int two(int x)
{
	int c[200005],len=0,res=0;
	while(x!=0)
	{
		c[++len]=x%2;
		x/=2;
	}
	for(int i=len;i>=1;i--) res*=10,res+=c[i];
	return res;
}
int andyu(int x,int y)
{
	int res=0;
	while(x!=0 && y!=0)
	{
		int tx=x%10,ty=y%10;
		x/=10,y/=10;
		res*=10;
		if(x==y) res+=1;
	}
	return res;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=two(a[i]);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int o=andyu(a[i],a[j]);
			maxn=max((ten(o)),maxn);
		}
	}
	cout<<maxn;
	return 0;
}
