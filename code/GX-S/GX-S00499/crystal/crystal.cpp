#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
ll m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		ll cnt=1,k=i;
		while(a[i]==a[k-1])k--,cnt++;
		i=k;
		ll j=i-1,m1=m;
		while((a[i]-a[j]<=m1)&&j>=1){
			cnt++;
			m1-=(a[i]-a[j]);
			j--;
		}
		ans=max(ans,cnt);
		if(j==0)break;
	}
	cout<<ans;
	return 0;
}
	
