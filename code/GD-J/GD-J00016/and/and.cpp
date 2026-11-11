#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	
		long long maxx;
		for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
		
		maxx=max(a[i],maxx);
	}
	cout<<maxx;
		
	
	/*if(n==m)
	{
	
	
	int b[500005],l,c[500005];
	long long sum;
	for(int i=1;i<=500000;i++)
	{
		c[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		l=0;
		cin>>a[i];
		for(int j=a[i];j>0;j/=2)
		{
			b[++l]=j%2;
		}
		for(int j=1;j<=l;j++)
		{
			if(b[j]==0)c[j]=0;
		}
	}
	for(int i=1;i<=500000;i++)
	{
		sum+=pow(2,i)*c[i];
	}
	cout<<sum;
	}*/
	return 0;
 } 
