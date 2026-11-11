#include <bits/stdc++.h>
using namespace std;
int n,m,m1;
int a[100000];
int maxn=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i=0;i<n;i++)
//	{
//		int s=0;
//		int x=a[i];
//		m=m1;
//		if(i!=0)
//		{
//			while(m!=0)
//			{
//				while(a[i]==x)
//				{
//					a[i]++;
//					m--;	
//				}		
//				s++;
//			}	
//		}
//	}	
	for(int i=0;i<n;i++)
	{
		int s=0;
		m=m1;
		for(int j=0;j<n;j++)
		{
			if(a[j]!=a[i]&&m!=0)
			{
				a[j]++;
				m--;
			}
			if(a[j]==a[i])
			{
				s++;
				break;	
			}	
		} 
		if(s>maxn)
		{
			maxn=s;	
		}	
	}
	cout<<maxn;
	return 0;
}
