#include <bits/stdc++.h>
using namespace std;
long long n,m;long long a[100086*5];long long b[5*100086];int maxx=-1;
int cmp(long long x,long long y)
{
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	if(n>5000)
	{
		for(int i=1;i<=n;i++)
	{
		if(a[i]*i-b[i]<=m)maxx=i;
		
	}
	}
	else if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j-i+1]*(j-i+1)-b[j-i]<=m)maxx=max(maxx,j-i+1);
			}
		}
	}
	
	cout<<maxx;
	return 0;
} 
