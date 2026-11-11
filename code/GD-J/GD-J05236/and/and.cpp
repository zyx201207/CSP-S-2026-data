#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
void solve()
{
	bool _task13=true;
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ll x=a[i]+1;
		if(x-(x&-x)!=0)_task13=false;
	}
	sort(a.begin()+1,a.begin()+1+n,[&](ll x,ll y){
		return x>y;
	});
	if(m==1)cout<<a[1];//task6
	else if(m==2)//task8~10
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i]!=a[j])ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else if(m==n)//task7
	{
		ll ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}
	else if(_task13)
	{
		ll ans=a[1];
		for(int i=2;i<=m;i++)	
			ans&=a[i];
		cout<<ans;
	}
	else if(n<=20)
	{
		ll ans=0;
		for(int chosen=0;(chosen<1<<n);chosen++)
		{
			ll res=-1,cnt=0;
			for(int i=0;i<n;i++)
			{
				if((chosen>>i)&1)
				{
					cnt++;
					if(res==-1)res=a[i+1];
					else res&=a[i+1];
				}
			}
			if(cnt==m)ans=max(ans,res);
		}
		cout<<ans;
	}
	else cout<<"qwq";
	return;
}
int main()
{
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie();
	ll T=1;//cin>>T;
	while(T--)solve();
	return 0;
}

