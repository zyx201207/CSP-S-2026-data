#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
bool f[200005];
int b[200005];
long long mx=0;
long long awy(int a[])
{
	if(m==1)
		return a[1];
	long long ans=a[2];
	for(int i=1;i<m;i++)
	{
		int _a[35],b[30],t=a[i],ta=ans,l=1,la=1;
		if(i==2)
		 continue;
		while(t)
		{
			_a[l++]=t%2;
			t/=2;
			l++;
		}
		l--;
		while(ta)
		{
			b[la++]=ta%2;
			ta/=2;
			la++;
		}
		la--;
		int c[30];
		for(int i=1;i<=max(l,la);i++)
		{
			if(_a[i]==1&&b[i]==1)
				c[i]=1;
			else
				c[i]=0;
		}
		int k=1;
		for(int i=1;i<=max(l,la);i++)
		{
			ans+=c[i]*k;
			k*=2;
		}
	}
	return ans;
}
void search(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			b[k]=a[i];
			f[i]=1;
			if(k==m)
			{
				long long ans=awy(b);
				if(ans>=mx)
				{
					mx=ans;
				}
				return;
			}
			search(k+1);
			f[i]=0;
			b[k]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	search(1);
	cout<<mx;
	return 0;
}  
