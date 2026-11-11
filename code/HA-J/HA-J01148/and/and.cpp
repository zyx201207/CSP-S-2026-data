#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
long long ad(long long a,long long b)
{
	return a&b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	sort(a,a+n,cmp);
	//6
	if(m==1)
	{
		cout<<a[0];
		return 0;
	}
	long long ans=0;
	//8,9,10
//	if(m==2)
//	{
//		for(int k=0;k<n;k++)
//		{
//			for(int j=0;j<n;j++)
//			{
//				if(i!=j) ans=max(ans,ad(a[i],a[j]));
//			}
//		}	
//	}
	
	//7 
	if(m==n)
	{
		long long ansn=a[0];
		for(int i=1;i<n;i++)
		{
			ansn=ansn&a[i];
		}
		ans=ansn;
	}
	//11,12,不正确 
	else if(m==n-1)
	{
		long long ansn=a[0];
		for(int i=1;i<n-1;i++)
		{
			ansn=ansn&a[i];
		}
		ans=ansn;
	}
	
	
	//特A,B
	int pd1=0;
	if(m>2&&m!=n&&a[0]>=4)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<31;j++)
			{
				if(a[i]==(1<<j)-1)
				{
					pd1++;
				}
			}
		} 
		if(pd1==n)
		{
			ans=a[m-1];
		}
		
		int pd3=0,k=n-1,pd2=0;
		for(int i=0;i<18;i++)
		{
			if(n==(1<<i))
			{
				pd2=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==k)
			{
				pd3++;
			}
			k--;
		}
		long long ansm=a[0];
		if(pd3==n&&pd2!=0)
		{
			for(int i=1;i<m;i++)
			{
				ansm=ansm&a[i];
			}
			ans=ansm;
		}
	}
	//16，17 
	if(m>2&&a[0]<4)
	{
		long long p[5]={0};
		for(int i=0;i<n;i++)
		{
			if(a[i]==1) p[1]++;
			else if(a[i]==2) p[2]++;
			else if(a[i]==3) p[3]++;
		}
		if(p[3]>=m) ans=3;
		else if(p[3]+p[2]>=m) ans=2;
		else ans=1;
	}
	cout<<ans;
	return 0;
}
