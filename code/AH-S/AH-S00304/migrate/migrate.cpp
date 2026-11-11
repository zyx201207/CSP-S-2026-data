#include<bits/stdc++.h>
using namespace std;
long long a[2000005],n,d;
int find1(long long t)
{
	int l=1,r=n;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(a[mid]>=t)
			r=mid-1;
		else
			l=mid+1;
	}
//	cout<<l<<"\n";
	
	return l;
	//a[l]>=t;
}
int find2(long long t)
{
	int l=1,r=n;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(a[mid]>t)
			r=mid-1;
		else
			l=mid+1;
	}
//	cout<<r<<"\n";
	return r;
}
int main()
{
	//至少3个月没写过代码了，我竟然还能写出t1，力竭了，我竟然还记得头文件和二分
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		map<long long,int>mp;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]+d<=a[n])
				mp[find2(a[i]+d)-1]++;
			if(a[i]-d>=a[1])
				ans+=mp[find1(a[i]-d)];
		}
		cout<<ans<<'\n';
			
	}
}
