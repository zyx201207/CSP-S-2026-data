#include<bits/stdc++.h>
using namespace std;
int c,t;
int n1,d1;
int n2,d2;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n1>>d1;
	int x[n1];
	for(int i=0;i<n1;i++)
	{
		cin>>x[i];
	}
	cin>>n2>>d2;
	int y[n2];
	for(int i=0;i<n2;i++)
	{
		cin>>y[i];
	}
	int b1[n1];
	int cnt1=0;
	for(int i=0;i<n1;i++)
	{
		if(i!=0&&x[i-1]>0)
		{
			b1[i]=abs(x[i]-x[i-1]);
		}
		else if(i!=0&&x[i-1]<0)
		{
			b1[i]=abs(x[i]+x[i-1]);
		}
	}
	for(int i=0;i<n1;i++)
	{
		if(b1[i]<d1)
		{
			cnt1++;
		}
	}
	cout<<cnt1/2<<endl;
	int b2[n2];
	int cnt2=0;
	for(int i=0;i<n2;i++)
	{
		if(i!=0&&y[i-1]>0)
		{
			b2[i]=abs(y[i]-y[i-1]);
		}
		else if(i!=0&&y[i-1]<0)
		{
			b2[i]=abs(y[i]+y[i-1]);
		}
	}
	for(int i=0;i<n2;i++)
	{
		if(b2[i]<d2)
		{
			cnt2++;
		}
	}
	cout<<cnt2/2;
	return 0;
}
