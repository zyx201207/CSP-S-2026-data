#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,a[500005],ans=0;
bool flag=true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<n;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			flag=false;
		}
	}
	if(flag){
		ll ji=a[2]-a[1],sum=0;
		for(ll i=1;i<=n;i++){
			sum+=ji*i;
			if(sum<=m){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll temp=m,cnt=0;
		for(ll j=i;j>=1;j--){
			if(a[i]-a[j]<=temp){
				temp=temp-(a[i]-a[j]);
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
