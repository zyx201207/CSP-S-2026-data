#include<bits/stdc++.h>
using namespace std;
int n;
bool A=true,B=true; 
long long a[500005],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]!=1)
		{
			A=false;
		}int b=int(sqrt(a[i]*2));
		if(b*(b+1)/2!=a[i])
		{
			B=false;
		}
	}
	if(A)
	{
		long long z;
		int x=1;
		while(z<=m)
		{
			z=x*(x+1)/2;
			x++;
		}
		cout<<x-1;
	}
	if(B)
	{
		int B1=int(sqrt(a[1]*2));
		int tnt=B1;
		while(B1+1<=m)
		{
			B1++;
			m=m-B1;
		}
		cout<<B1-tnt+1;
	}
//	sort(a+1,a+n+1);
//	long long d=a[1];
//	while(m>ans){
//		
//		ans=max(ans,q);
//	}
//	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
