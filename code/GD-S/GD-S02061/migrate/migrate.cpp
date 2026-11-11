#include<bits/stdc++.h>
using namespace std;
const ll N = 2e6 + 5;
ll c,T,n,d,x[N],s[35][35],minn=0x3f3f3f3f3f3f3f3f,id;
ll check(ll x,ll end,ll num)
{
	if(x==end) return 1;
	ll ss=0x3f3f3f3f3f3f3f3f;
	for(int i=x+1;i<=end;i++)
	{
		if(a[i]-a[x]<=d)
		{
			ss=min(ss,check(i,end,0));
		}
	}
	ss+=num;
	if(ss<minn) minn=ss,id=1;
	else id++;
	return ;
}
void solve()
{
	ll ans=0;
	cin>>n>>d;
	if(n>5005) exit(0);
	for(int i=1;i<=n;i++) 
	{
		for(int j=i+1;j<=n;j++)
		{
			
			if(check(i,j,num)==2) ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
