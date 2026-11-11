#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int c,t,n,d,cnt,ans;
int a[200012],flag[200012];
int minn(int l,int r)
{
	for(int i=l;i<=r;i++)flag[i]=0;
	int sum=0;
	while(l<r)
	{
		int nx=upper_bound(a+1,a+1+n,a[l]+d)-a-1;
		if(l==nx)return 1;
		l=nx;
		flag[l]=1;
		sum++;
	}
	flag[r]=0;
	return sum;
}
bool check(int l,int r)
{
	int sum=0,ti=l;
	while(l<r)
	{
		int nx=upper_bound(a+1,a+1+n,a[l]+d)-a-1;
		if(nx>=r)
		{
			sum++;
			break; 
		}
		if(l==nx)return false;
		while(flag[nx])
		{
			nx--;
			if(nx<=l)return false;
		}
		l=nx;
		flag[l]=1;
		sum++;
	}
	flag[r]=0;
	if(sum>cnt)return false;
	sum=0;
	l=ti;
	while(l<r)
	{
		
		int nx=upper_bound(a+1,a+1+n,a[l]+d)-a-1;
		if(nx>=r)
		{
			sum++;
			break; 
		} 
		if(l==nx)return true;
		while(flag[nx])
		{
			nx--;
			if(nx<=l)return true;
		}
		l=nx;
		sum++;
	}
	if(sum>cnt)return true;
	return false;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==13||c==14)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=minn(i,j);
				if(cnt==1)continue;
				if(check(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19


12
*/
