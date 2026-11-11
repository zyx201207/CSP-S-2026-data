#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],mem[N],dp[N];
long long n,m;
long long dfs(long long x,long long vp)
{
	if(x>n)
	{
		return 0;
	}
	long long cnt=a[x]-a[x-1];
	cnt*=(x-1);
	if(cnt>vp)
	{
		return 0;
	}
	if(mem[x])
	{
		return mem[x];
	}
	long long sum=0;
	if(cnt<=vp)
	{
		sum=max(dfs(x+1,vp),dfs(x+1,vp-cnt)+1);
	}
	mem[x]=sum;
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<dfs(1,m)<<endl;
	return 0;
} 
