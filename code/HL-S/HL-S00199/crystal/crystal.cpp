#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009],maxn=-100009,n,m;
void dfs(ll moves)
{
	ll maxx=0;
	for(ll i=1;i<=n;i++)
	{
		ll cnt=0;
		for(ll j=1;j<=n;j++) if(a[j]==a[i]) cnt++;
		maxx=max(maxx,cnt); 
	}
	maxn=max(maxn,maxx);
	if(moves==0) return;
	for(ll i=1;i<=n;i++)
	{
		a[i]++;
		dfs(moves-1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll diff=a[2]-a[1],flag=1;
	for(ll i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=diff)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		//cout<<"YESYESYES!"<<endl;
		ll xxx=0;
		if((1+xxx)*xxx/2<=m)
		{
			do
			{
				xxx++;
			}while((1+xxx)*xxx/2<=m);
		}
		cout<<xxx-1;
		return 0;
	}
	dfs(m);
	cout<<maxn;
 }
