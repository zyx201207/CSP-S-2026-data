#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll tot=0;
	int ans=0;
	int l=1;
	for(int i=1;i<=n;i++){
		ll z=a[i]-a[i-1];
		while(l<i&&(i-l)*z>m-tot){
			tot-=(a[i-1]-a[l]);
			l++;
		}
		tot+=((i-l)*z);
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
