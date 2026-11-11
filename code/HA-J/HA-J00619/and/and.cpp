#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,a[N];
int qy(int x)
{
	int oo=0;
	int sum=0;
	while(x!=0)
	{
		sum=sum*10+x%2;
		x/=2;
		if(sum==0)
		{
			oo++;
		}
	}
	return sum*pow(10,oo);
}
struct work
{
	int x,num;
}s[N];
bool mysort(work x,work y)
{
	return x.x>y.x;
}
int andys(int x,int y)
{
	int w=0,oo=0;
	while(x!=0||y!=0)
	{
		if(x%10==y%10&&x%10==1)
		{
			w=w*10+1;
		}
		x/=10;
		y/=10;
		if(w==0)
		{
			oo++;
		}
	}
	return w*pow(10,oo);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i].x=qy(a[i]);
	}
	sort(s+1,s+n+1,mysort);
	long long ans=s[1].x;
	for(int i=2;i<=m;i++)
	{
		ans=andys(ans,s[i].x);
	}
	int sum=0,temp=0;
	while(ans!=0)
	{
		sum+=ans%10*pow(2,temp);
		temp++;
		ans/=10;
	}
	cout<<sum;
	
	
	return 0;
}
