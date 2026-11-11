#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=100005;
ll a[N];
ll n,m,ans;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=2;i<=m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
