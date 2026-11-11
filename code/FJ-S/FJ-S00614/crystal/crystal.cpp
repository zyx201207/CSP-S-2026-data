#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n;
	cin>>n>>m;
	if(m==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++)
		cin>>a[i];
	bool f=0;
	for(int i=0;i<n-1;i++)
		if(a[i]!=a[i+1])
			f=1;
	if(f==0)
	{
		cout<<n;
		return 0;
	}
	sort(a,a+n);
	int zws=a[n/2],num=0,j=n/2-1;
	while(j>=0)
	{
		if(m-(zws-a[j])<=0)
		{
			if(m-(zws-a[j])==0)
			{
				m-=zws-a[j];
				a[j]=zws;
				break;
			}
			else
				break;
		}
		m-=zws-a[j];
		a[j]=zws;
		j--;
	}
	if(j!=-1)
	{
		for(int i=0;i<n;i++)
			if(a[i]==zws)
				num++;
		cout<<num;
	}
	else
	{
		int bj;
		for(int i=0;i<n;i++)
		{
			if(a[i]==zws)
				num++;
			else
			{
				bj=i;
				break;
			}
		}
		while(bj<n)
		{
			if(m<num*(a[bj]-zws))
				break;
			m-=num*(a[bj]-zws);
			zws=a[bj];
			bj++;
			num++;
		}
		cout<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
