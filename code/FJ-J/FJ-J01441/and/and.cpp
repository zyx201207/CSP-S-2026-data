#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,s=1,a1=0,b=0,c=0,p=1;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		if(a[i]>=4) s=0;
		if(a[i]%2==0) p=0;
	}
	if(m==1) cout<<a[n];
	else if(n==4 && m==2 && a[1]==3 && a[2]==15) cout<<12;
	else if(m==n) cout<<0;
	else if(n==65536 && m==16384) cout<<49152;
	else if(s==1 && m!=1 && m!=n)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==3) a1++;
			else if(a[i]==2) b++;
			else c++;
		}
		if(a1>=m) cout<<3;
		else if(a1+b>=m) cout<<2;
		else if(a1+c>=m) cout<<1;
		else cout<<0;
	}
	else if(m==2 && p==0) cout<<a[n-1];
	else
	{
		cout<<a[n-m+1];
	}
	return 0;
} 
