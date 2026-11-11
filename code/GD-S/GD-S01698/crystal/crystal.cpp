#include<bits/stdc++.h>
using namespace std;long long b[100005]={0},a[100005];	long long n,m;
int cmp(int x,int y)
{
	return x<y;
}

int main()
{
freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int sss=0,ss=0;
	for(long long i=2;i<=n;i++)
	{
		b[i]=b[i-1]+abs(a[i-1]-a[i]);
		if(abs(a[i-1]-a[i])!=0)
		{
			ss=max(ss,sss);sss=0;
		}
	 sss++;
	//	cout<<b[i]<<' ';
	//	cout<<abs(a[i-1]-a[i])<<' '<<i<<a[i-1]<<a[i]<<endl;
	}
/*	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		//cout<<1;
		if(b[i]>m)
		{
			ans=i-1;
			break;
		}
		cout<<b[i]<<' ';
	}
	
	cout<<ans;*/

	long long l=1,r=n,ans=0,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(b[mid]<=m)
		{
			//cout<<2;
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
			//cout<<1;
		}
	}
	cout<<ans;	

 } 
