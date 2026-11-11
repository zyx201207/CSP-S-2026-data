#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[50010],sum=0,maxz=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		long long m1=m;
		sum=0;
		for(int j=1;j<=i;j++)
		{
			m1-=a[i]-a[j];
			sum++;
			if(m1<0)
			{
				break;
				
			}
		}
		maxz=max(maxz,sum);
	}
		
	cout<<maxz;
	return 0;
} 
