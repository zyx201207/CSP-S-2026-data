#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[7000000],maxs=0;
long long n,m,k,maxid=-100000,minid=200;
int glf(int h,int t)
{
	if(h==n+1)
	{
		int d=0,f=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1||a[i]==t) d+=1;
			else
			{
				if(f<d) f=d;
				d=0;
			}
		}
		if(maxs<f) maxs=f;
		return 1;
	}
	int dfg=1;
	if(a[h]<t&&t-a[h]<=k)
	{
		k=k-t+a[h];
		b[h]=1;
		h++;
		dfg=0;
		glf(h,t);
	}
	if(dfg==0) 
	    k=k+t-a[h];
	b[h]=0;
	if(dfg==1) h++;
	glf(h,t);
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	int sf=1,s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) s=a[i]-a[i-1];
		if(i==3&&sf==1)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) sf=0;
		}
		if(a[i]>maxid) maxid=a[i];
		if(a[i]<minid) minid=a[i];
	}
	if(sf==1)
	{
		int c=0,q=0;
		while(m>=c)
		{
			q+=1;
			c+=q*s;
		}
		cout<<q;
		return 0;
	}
	k=m;
	for(int i=maxid;i>=minid;i--)
	{
		glf(1,i);
	}
	cout<<maxs+2;
	return 0;
}
