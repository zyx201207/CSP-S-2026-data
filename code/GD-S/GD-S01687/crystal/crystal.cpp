#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,maxx=-1,rm;
ll a[500005],f[500005],d[500005];
int main()
{
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin>>n>>m;
	rm=m;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	d[n]=a[n];
	for(int i=1;i<=n;i++)
	{
		ll val=0,id=i;
		if(maxx==n)
		{
			fout<<n;
			return 0;
		}
		if(n-id+1<maxx)
		{
			break;
		}
		while(val<=m&&id<=n)
		{
			if(val+(id-i+1)*d[id]<=m){
				val+=((id-i+1)*d[id]);
				id++;
			}
			else
			{
				maxx=max(id-i+1,maxx);
				break;
			}
		}
	}
	fout<<maxx;
	fin.close();
	fout.close();	
} 
