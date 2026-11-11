#include<bits/stdc++.h>
using namespace std;
int n;
double m;
int a[50005],add[50005];
long long c,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flag=0;
	for(int i=1;i<n;i++)
	{
		add[i]=a[i+1]-a[i];
		if(add[i]!=1)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		m*=2;
		for(int i=1;i<=sqrt(m);i++)
		{
			if(i*i+i==m)
			{
				cout<<i;
				exit(0);
			}
			if(i*i+i<m)
			{
				long long t=i;
				ans=max(ans,t);
			}
		}
		cout<<ans;
		exit(0);
	}
	//sum[i]-sum[i-n(集合元素数)+1]==m(总和即操作次数);
	bool f=0;
	for(int i=n-1;i>=1;i--)
	{
		//cout<<"lengthed"<<i<<":"<<"\n";
		for(int j=n-1;j>=i;j--)
		{
			c=0;
			int f=i;
			for(int l=j;l>=j-i+1;l--)
			{
				c+=add[l]*f;
				f--;                                      
			//	cout<<add[l]<<" "<<f+1<<"\n";
			}
			
			//cout<<j<<"-"<<j-i+1<<"="<<c<<"\n";
			if(c==m)
			{
				f=1;
				cout<<i+1;
				exit(0);
			}
			if(c<m)
			{
				long long f=i+1;
				ans=max(ans,f);
			}
		}
		//cout<<"\n";
	}
	if(f==0)
	{
		cout<<ans;
	}
}
