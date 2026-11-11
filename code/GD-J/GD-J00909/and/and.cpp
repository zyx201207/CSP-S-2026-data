#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[200005],c[200005],t,da,da2,s;
void dfs(int k,int x)
{
	if(k==x+1)
	{
		int sum=c[1];
		for(int i=2;i<=x;i++)
		sum&=c[i];
		da2=max(da2,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			c[++t]=a[i];
			dfs(i+1,x);
			b[i]=0;
			t--;
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		da=max(da,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(m==1)
	{
		cout<<da;
		return 0;
	}
	if(n<=2000&&m==2)
	{
		da=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				da=max(da,a[i]&a[j]);
			}
		}
		cout<<da;
		return 0;
	}
	if(m==n)
	{
		s=a[1];
		for(int i=2;i<=n;i++)
		s=s&a[i];
		cout<<s;
		return 0;
	}
	if(n<=10)
	{
		dfs(1,m);
		cout<<da2;
		return 0;
	}
	int s=a[1];
	for(int i=2;i<=m;i++)
	s&=a[i];
	cout<<s;
	return 0;
}
