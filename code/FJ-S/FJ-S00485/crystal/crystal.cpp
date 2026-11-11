#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],tmp=0,crystal=0,cnt=0,maxwww=0;
long long tmppp(long long www)
{
	for (int i=1;i<=n;i++)
	{
		if(a[i]==www)
		{
			tmp=a[i];
			return 0;
		}
	}
	maxwww=-10000000000001;
	for (int i=1;i<=n;i++)
	{
		if(a[i]>maxwww){
			if(a[i]<=tmp){
				maxwww=a[i];
			}
		}
	}
	tmp=maxwww;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long max=-10000000000001,min=10000000000001;
	cin>>n;
	cin>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
		else if(a[i]<min)
		{
			min=a[i];
		}
	}
	tmp=(max+min)/2;
	sort(a,a+n+1);
	tmppp(tmp);
	
	for(int i=n-1;i>1;i--)
	{
		if(a[i]<=tmp)
		{
			cnt++;
			crystal+=tmp-a[i];
		}
		if(crystal>m){
			cout<<cnt;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}
