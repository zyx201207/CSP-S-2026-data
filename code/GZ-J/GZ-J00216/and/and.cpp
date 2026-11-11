//GZ-J00216 敖德钦 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,c,p,x=-1,a[200006],l,l1,u;
//string s,s1,s2,s3,s4;
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	a[0]=-1;
	cin>>n>>m;
	for(long long  i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
		for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			//cout<<a[i] and a[j];
			if(a[i]!=-1&&a[j]!=-1)
			{
				//cout<<a[i] and a[j];
				if((a[i]) & (a[j])>x)
				{
					x=(a[i]) & (a[j]);
					l=i;
					l1=j;//cout<<x;
				}
			}
		}
	
	
	a[l]=-1;
	a[l1]=-1;
	
	}
	if(m>2)
	{
		for(long long k=2;k<=m;k++)
		{
			for(long long j=1;j<=n;j++)
		{
			//cout<<a[i] and a[j];
			if(a[j]!=-1)
			{
				//cout<<a[i] and a[j];
				if((x) & (a[j])>u)
				{
					u=(x) & (a[j]);
					l1=j;//cout<<x;
				}
			}
		}
	    x=u;
		a[l1]=-1;
		u=0;
	    }
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

