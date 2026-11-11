#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[200005],s[200005];
long long r;
void dfs(int u,int l,int ans)
{
	if(l==m)
	{
		sum=max(sum,ans);
		return ;
	}
	if(u==n+1)
		return ;
	if(l>m)
		return ;
	dfs(u+1,l+1,ans&a[u]);
	dfs(u+1,l,ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int q=0,k=1,f=0,h=0;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q=max(q,a[i]);
		k=max(k,a[i]-a[i-1]);
		h=max(h,a[i]);
	}
	if(m==1)
	{
		cout<<q;
		return 0;
	}
	if(n<=20)
	{
		for(int i=1;i<n;i++)
		{
			dfs(i+1,1,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(n==m)
	{
		r=a[1];
		for(int i=2;i<=n;i++)
			r&=a[i];
		cout<<r;
		return 0;
	}
	if(m==2)
	{
		int w=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				w=max(w,(a[i]&a[j]));
		cout<<w;
		return 0;
	}
	if(h<4)
	{
		int qq=0,ww=0,ee=0,rr=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
				qq++;
			if(a[i]==1)
				ww++;
			if(a[i]==2)
				ee++;
			if(a[i]==3)
				rr++;
		}
		if(m<=rr)
			cout<<3;
		else if(m<=rr+ee)
			cout<<2;
		else if(m<=rr+ww)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
