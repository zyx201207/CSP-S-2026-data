#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
long long a[N];
long long k[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		k[a[i]]+=1;
		if(i!=1&&a[i]!=a[i-1])
			f=0;
	}
	if(f==1)
	{
		cout<<n;
		return 0;
	}
	long long maxx=0,maxt=0;
	for(int i=1;i<=n;i++)
	{
		long long s=0,b=m;
		for(int j=1;j<=n;j++)
		{
			long long h=abs(a[j]-a[i]);
			if(b-h>=0)
			{
				s+=1;
				b-=h;
			}
			else
			{
				break;
			}
		}
		maxx=max(maxx,s);
		//cout<<endl;
	}
	cout<<maxx;
	return 0;
}
