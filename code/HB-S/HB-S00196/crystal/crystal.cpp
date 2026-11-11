#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[50000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	int mun=-1,m2=m;
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		int j=1;
		int mun2=0;
		m=m2-0;
		while(flag!=0)
		{
			if(a[j]<a[i])
			{
				m-=a[i]-a[j];
				if(m>=0)
				mun2++;
				else
				flag=0;
			}
			else if(a[j]==a[i]) mun2++;
			else if(m<=0) flag=0;
			if(j==n) flag=0;
			
			  j++;
		}
		mun=max(mun2,mun);
}
	cout<<mun;
	 
	return 0;
}
