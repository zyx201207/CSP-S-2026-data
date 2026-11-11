#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
ll n,m,ans;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll i,j,k,x;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1,j=x=0;i<=n;i++){
		x+=a[i];
		while(j<i&&x+m<a[i]*(i-j))j++,x-=a[j];
		ans=max(ans,i-j);
	}
	cout<<ans<<"\n";
}
