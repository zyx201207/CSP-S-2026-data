#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,k,t1;
int a[N];
int mx=-1,ans=-1;
void dfs(int step,int t,int v)
{
	if(step>n){
		if(t==k)
			ans=max(ans,v);
		return ;
	}
	if(t==k){
		ans=max(ans,v);
		return ;
	}
	if(t==0) v=a[step];
	dfs(step+1,t+1,v&a[step]);
	dfs(step+1,t,v);
}
bool check(int x)
{
	bool f=1;
	while(x>0)
	{
		if(x%2!=1) f=0;
		x/=2;
	}
	return f;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	bool b=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
		if(!check(a[i]))
		{
			b=0;
		}
	}
	t1=a[1];
	for(int i=1;i<=n;i++)
		t1&=a[i];
	if(n==k){
		cout<<t1;
		return 0;
	}
	if(k==1)
	{
		cout<<mx;
		return 0;
	}
	if(b)
	{
		sort(a+1,a+n+1);
		cout<<a[n-k+1];
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
