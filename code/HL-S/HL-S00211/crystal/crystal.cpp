#include<bits/stdc++.h>
using namespace std;
int ar[600000]={0},l=1;
long long n,m;
int cmp(long long a,long long b)
{
	return a<=b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
		if(i>=3&&ar[i]-ar[i-1]!=ar[i-1]-ar[i-2]);
		{
			l=0;
		}
	}
	sort(ar+1,ar+n+1,cmp);
	if(l==0)
	{
		long long ma=1;
		for(int i=1;i<=n;i++)
		{
			int mm=m,a=i,s=1;
			while(mm)
			{
				if(a<=1)break; 
				mm-=(ar[i]-ar[a-1]);
				if(mm>=0)
				{
					s++;
					a--;
				}
				else
				{
					break;
				}
				
			}
			if(s>ma)
			{
				ma=s;
			}
		}
		cout<<ma;
	}
	else
	{
		m/=(ar[2]-ar[1]);
		int s=0;
		for(int i=1;i<n;i++)
		{
			s+=i;
			if(s>m)
			{
				cout<<i;
				break;
			}
		}
	}
	return 0;
} 
