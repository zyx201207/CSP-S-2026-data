#include<bits/stdc++.h>
using namespace std;
long long m,n,sum=0,snm=0;
long long a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		snm=max(a[i],snm);
	}
	sort(a,a+n+1);
	for(int i=1;i<n;i++)
	{
		for(int j=m;j>=1;j+=0)
		{
			if(a[i]<a[i+1])
			{
				a[i]++;
				m--;
			}
			if(a[i]==a[i+1])
			break;
			if(a[i+1]>=a[i])
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		b[a[i]]=0;
		b[a[i]]++;
	}
	for(int i=1;i<=snm;i++)
	{
		if(b[i]==b[i+1]) sum++;
		sum=max(b[i],sum);
	}
	cout<<sum;
	return 0;
}
