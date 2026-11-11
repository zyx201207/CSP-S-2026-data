#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll a[N],b[N];
bool cmp(ll a,ll b)
{
	return a<b; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	
	sort(a+1,a+1+n,cmp);
		
	b[0]=0;
	for(int i=1; i<=n; i++)
		b[i]=b[i-1]+a[i];
	
	ll t,mx=-1e12;
	for(ll i=1; i<=n; i++)
	{
		ll s=m-((i*a[i])-b[i]);
		if(s<0)
			break;
		mx=i;
	}
	
	cout<<mx<<'\n';
	return 0;
}
