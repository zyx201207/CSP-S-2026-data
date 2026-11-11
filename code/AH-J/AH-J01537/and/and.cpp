#include<bits/stdc++.h>
using namespace std;
long long ans[35];
string a[200005],b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,n,m,x,t,k=0,maxn=-1;
	string s;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		maxn=max(maxn,x);
		while(x)
		{
			s=s+char('0'+x%2);
			x=x/2;
		}
		a[i]=s;
		s="";
	}
	if(m==1)
	{
		cout<<maxn;
		exit(0);
	}
	for(i=30;i>=0;i--)
	{
		t=0;
		for(j=1;j<=n;j++)
		{
			long long o=a[j].size();
			if(o>=i+1)
			{
				string p=a[j];
				if(p[i]=='1')
				{
					t++;
					b[t]=p;
				}
			}
		}
		if(t>=m)
		{
			for(j=1;j<=t;j++)
			{
				a[j]=b[j];
			}
			n=t;
			ans[i]=1;
		}
	}
	for(i=30;i>=0;i--)
	{
		k=k*2+ans[i];
	}
	cout<<k;
}
