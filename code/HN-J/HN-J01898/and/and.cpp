#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

long long aa(long long a)
{
	long long s=0,k,z=1;
	while(a>0)
	{
		k=a%2;
		s=k*z+s;
		a=a/2;
		z=z*10;
	} 
	return s;
}

long long bb(long long a)
{
	long long s=0,z=1,k;
	while(a>0)
	{
		k=a%10;
		s=s+k*z;
		a=a/10;
		z=z*2;
	}
	return s;
}

long long n,m,a[200005],i,j,s;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	s=a[1];
	
	sort(a+1,a+1+n,cmp);
	
	s=aa(a[1]);
	
	for(j=2;j<=m;j++)
	{
		s=s and aa(a[j]);
	}
	cout<<bb(s);
	cout<<" "<<bb(aa(3) and aa(12));
}
