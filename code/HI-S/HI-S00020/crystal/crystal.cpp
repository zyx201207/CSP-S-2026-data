#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,ans=INT_MIN;
ll a[N],sum[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<ll>() );
	for(int i=2;i<=n;i++){
		
		ll flag=a[i-1];
		ll mm=m;
		
		for(int j=i;j<=n;j++){
			
			if(a[j]==flag){
				continue;
			}
			else{
				
				ll p=mm-(flag-a[j]);
				if(p>0){
					
					a[j]+=flag-a[j];
					mm-=(flag-a[j]);
					sum[j]++;
					
				}
				
				else{
					continue;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,sum[i]);
	}
	cout<<ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t=1;
	while(t--){
		solve();
	}
	return 0;
} 
