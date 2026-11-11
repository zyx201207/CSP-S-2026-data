#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[500005];
int b[500005];
int main()
{
	//fuck
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,Max=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	bool o=false;
	for(int i=1;i<n;i++)
	{
		b[i]=a[i]-a[i-1];
		if(b[i]!=0)
		{
			o=true;
		}
	}
	if(o==true)
	{
		for(int i=1;i<n;i++)
		{
			int x=0;
			int num=0;
			while(x<m)
			{
				x+=b[i]*(num+1);
				num++;
			}
			Max=max(num,Max);
		}
		cout<<Max;
	}
	else
		cout<<max(m%n,n-m%n);
	return 0;
}
