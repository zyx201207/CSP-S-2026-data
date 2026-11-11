#include<bits/stdc++.h>
using namespace std;
long long q[35],a[35],n,m,b[200005];
long long s,t,maa,ma,ma1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	q[1]=1;
	for(int i=2;i<=31;i++)
	{
		q[i]=q[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		ma1=max(ma1,b[i]);
		for(int j=30;j>=1;j--)
		{
			if(b[i]>=q[j])
			{
				a[j]++;
				b[i]=b[i]-q[j];
			}
		}
	}
	if(m==1)
	{
		cout<<ma1;
	}
	else if(m==n)
	{
		for(int i=1;i<=30;i++)
		{
			if(a[i]==m)
			{
				ma=ma+q[i];
			}
		}
		cout<<ma;
	}
}	
