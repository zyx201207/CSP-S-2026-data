#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],r=1,ans,pp,maxl,p[200005],x[200005][35],s;
bool cmp(int a,int b)
{
	return a>b;
}
void e(long long a,int i)
{
	long long l=0;
	while(a)
	{
		l++;
		x[i][l]=a%2;
		a/=2;
	}
	maxl=max(l,maxl);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		e(a[i],i);
	}
	for(int i=1;i<maxl;i++)
	{
		r=r*2;
	}
	for(int i=maxl;i>=1;i--)
	{
		s=0;
		for(int j=1;j<=n;j++)
		{
			if(pp==1)
			{
				if(p[j]==1)
				{
					if(x[j][i]==1)
					{
						s++;
					}
					else
					{
						p[j]=0;
					}
				}
			}
			else
			{
				if(x[j][i]==1)
				{
					s++;
				}
			}
		}
		if(s>=m)
		{
			ans=ans+r;
			if(pp==0)
			{
				for(int j=1;j<=s;j++)
				{
					p[j]=1;
				}
				pp=1;
			}
		}	
		r/=2;
	}
	cout<<ans;
	return 0;
}
