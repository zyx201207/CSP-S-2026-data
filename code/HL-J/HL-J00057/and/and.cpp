#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+10;
long long a[N];
long long b[N];
long long sum=INT_MAX;
long long cnt;
long long n,m;
void dfs(long long sum,int c)
{
	//cout<<c<<"sum"<<sum<<endl;
	if(c==m)
	{
		cnt=max(cnt,sum);
		return;
	}
	if(sum<cnt)
	{
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(b[i]==0)
		{
			b[i]=1;
			dfs(sum&a[i],c+1);
			b[i]=0;
		}
	}
}
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n]<<'\n';
		return 0;
	}
	if(m==n)
	{
		
		for(long long i=1;i<=n;++i)
		{
			sum=sum&a[i];
		}
		cout<<sum<<'\n';
		return 0;
	}
	dfs(sum,0);
	
	cout<<cnt<<endl;
	return 0;
}