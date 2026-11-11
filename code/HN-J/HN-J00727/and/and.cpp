#include <iostream>
#include <cstdio>
using namespace std;
int n,m,maxn,b;
int a[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>maxn)
			maxn=a[i];
		}
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				if(a[i]&a[j]>maxn) maxn=a[i]&a[j];
			}
	}
	else
	{
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++)
				{
					b=a[i]&a[j]&a[k];
					if(b>maxn) maxn=b;
				}
	}
	cout<<maxn<<endl;
	b=a[0]&a[3]&a[4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
