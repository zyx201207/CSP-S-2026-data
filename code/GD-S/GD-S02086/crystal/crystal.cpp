#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

long long n,m;
long long e[N];
long long ans;
long long sum[N];

bool fin(long long u,long long v)
{
	long long val=sum[u]-sum[v-1];
	val=(u-v+1)*e[u]-val;
	if(val>m)
	{
		
		return false;
	}
	return true;
}

long long fun(long long pos)
{
	
	long long res=0;
	long long l=1;
	long long r=pos;
	while(l<=r)
	{
		long long mi=(l+r)>>1;
		if(fin(pos,mi))
		{
			//cout<<mi<<endl;
			res=max(pos-mi+1,res);
			r=mi-1;
		}
		
		else
		{
			
			l=mi+1;
		}
	}
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		
		cin>>e[i];
		
		
		
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		
		sum[i]=sum[i-1]+e[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		
		ans=max(ans,fun(i));
		//cout<<ans<<" "<<i<<endl;
	}
	
	cout<<ans<<endl;
	
	
	//cout<<fun(n)<<endl;
	return 0;
}
