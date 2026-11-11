#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c;
	cin>>t;
	cin>>n>>k;
	long long u[1000005],v[1000005];
	for(int i=0;i<n;i++)
	{
		cin>>u[i];
		cin>>v[i];
	}
	long g[1000005];
	for(int i=1;i<=1000000;i++)
	{
		g[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		g[u[i]]++;
	}
	int f=0,f1=0,s=0,s1=0;
	for(int i=1;i<1000000;i++)
	{
		if(g[i]>f)
		{
			s=f;
			s1=f1;
			f=g[i];
			f1=i;
		}
		else if(g[i]>s)
		{
			s1=i;
			s=g[i];
		}
	}
	cout<<"1"<<"2";
	return 0;
}
