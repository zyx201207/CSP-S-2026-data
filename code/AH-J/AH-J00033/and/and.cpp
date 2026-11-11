#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int a[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(m==1)
	{
		sort(a,a+n);
		cout<<max(a[0],a[n-1]);
	}
	else if(m==2)
	{
		int mx=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(same(a[i],a[j])>max)
					max=same(a[i],a[j]);
			}
		}
		cout<<max;
	}
	return 0;
}
