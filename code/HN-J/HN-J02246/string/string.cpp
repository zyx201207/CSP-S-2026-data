#include<bits/stdc++.h>
using namespace std;
long long a[200001]={0};
char m[200001],nn[200001];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,b,c=0,x,s=0;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>y;
		if(y==m[i])
		{
			x=i-1;
			while(a[x]=0)
			{
				x--;
			}
			a[x]+=b;
		}
		else
		{
			nn[i]=y;
			a[i]+=b;
			c++;
		}
		s+=b;
		m[i]=y;
	}
	if(c==1)
	{
		cout<<0;
		return 0;
	}
	long long z,mm=1,len=0,q=0;
	if(s%2==1)
	{
		s=s/2+1;
		while(s>q)
		{
			q+=a[mm];
			mm++;
		}
		a[mm-1]--;
		z=mm-1;
	}
	else
	{
		z=c/2;
	}
	mm=1;
	while(a[z]!=0)
	{
		if(nn[c]!=nn[mm])
		{
			len+=min(a[mm],a[c]);
		}
		a[mm]-=min(a[mm],a[c]);
		a[c]-=min(a[mm],a[c]);
		if(a[c]==0)
		{
			c--;
		}
		else if(a[mm]==0)
		{
			mm++;
		}
	}
	cout<<len;
	return 0;
}
