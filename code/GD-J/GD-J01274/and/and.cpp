#include<bits/stdc++.h> 
using namespace std;
long long and1(long long a,long long b)
{
	long long sum;
	while(min(a,b)>0)
	{
		if(a%10==b%10&&a%10==1)sum=sum*10+1;
		else sum*10;
		a/=10;
		b/=10;	
	}	
	return sum;
}
long long zh(long long a)
{
	long long s,i=0;
	while(a!=0)
	{
		s=a%2*pow(10,i)+s;
		a/=2;
		i++;
	}
	
	return s;
}
long long h(long long a)
{
	long long s;
	while(a!=0)
	{
		long long i;
		s=a%10*pow(2,i)+s;
		a/=10;
		i++;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cout<<h(111)<<' ';
	long long n,m,a[100010],maxz=0,c=1,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxz=max(maxz,a[i]);
		a[i]=zh(a[i]);
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<maxz;
		return 0;
	}
	maxz=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			long long s=and1(a[i],a[i+1]);
			maxz=max(maxz,s);
		}
		cout<<h(maxz);
		return 0;
	}
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]%10==a[i-1]%10&&a[i]%10==1)c=1,a[i]/10,a[i-1]/10;
			else 
			{
				c=0;
				break;
			}
		}
		if(c==1)sum=sum*10+1;
		else sum*10;
		cout<<h(sum);
	}
		
	return 0;
}
