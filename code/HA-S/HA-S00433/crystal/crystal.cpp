#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000006],maxc=0,tmac=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long h=1;h<=n;h++)
	{
		cin>>a[h];
		
	}
	long long x=m;
	for(long long i=1;i<=1000000;i++){
		for(long long j=1;j<=n;j++)
		{
			if(a[j]<=i)
			{
				maxc++;
				x-=i-a[j];
			}
		}
		if(x>=0&&maxc>=tmac)
			tmac=maxc;
		if(x<0)
			break;
	}
	cout<<tmac;
	return 0;
}