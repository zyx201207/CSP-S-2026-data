#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const ll N=1e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
ll c,t,n,d;
ll a[N];
ll minn,num;
void dfs(ll x,ll ed,ll sum)
{
	if(x==ed)
	{
		if(sum==minn) num++;
		if(sum<minn) minn=sum,num=0;
		return;
	}
	f(i,x+1,ed)
	{
		if(a[i]-a[x]>d) break;
		dfs(i,ed,sum+(a[i]-a[x]));
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cout.tie(0),cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ll ans=0;
		f(i,1,n) cin>>a[i];
		f(i,1,n)
		{
			f(j,i+1,n)
			{
				minn=inf,num=0;
				dfs(i,j,0);
				if(num==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}























































