#include <bits/stdc++.h> 
using namespace std;
long long a[2000005];
long long d[2000005];
bool v[2000005];
long long sum;
void dfs(long long r,long long x,long long len)
{
	if(x==r) sum++;
	for(long long i=r;i<=x;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			if(d[i]-d[r]>len) return ;
			dfs(i,x,len);
			v[i]=0;
		} 
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,l;
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>l;
		for(long long i=1;i<=n;i++)
			cin>>a[i];
		for(long long i=1;i<=n;i++)
			d[i]=a[i]-a[i-1];
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<i;j++)
			{
				dfs(j,i,l);
//				cout<<j<<" "<<i<<" "<<sum/4<<endl;111
				if(sum/4==2)
					ans++;
				sum=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
