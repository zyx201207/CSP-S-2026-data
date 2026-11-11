#include<bits/stdc++.h>
using namespace std;
int c,n,t,d,cnt,ans,f[2000005];
vector<int> x;
int most(int a)
{
	for(int i=a;;i++)
	{
		if(x[i]-x[a]>d)
		{
			return i-1;
		}
	}
}
void road(int begin,int end)
{
	int nex=most(begin);
	ans++;
	if(nex>=end) 
	{
		return;
	}
	for(int i=begin+1;i<nex;i++)
	{
		road(i,end);
	}
	return;
}
bool check(int a,int b)
{
	for(int i=a;i<b;i++)
	{
		if(f[i]==1) return 1;
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++)
	{
		x.resize(0);
		x.push_back(INT_MAX);
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			x.push_back(a);
		}
		for(int i=1;i<n;i++)
		{
			if(x[i+1]-x[i]>d) f[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(check(i,j)) continue;
				ans=0;
				road(i,j);
				if(ans==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
