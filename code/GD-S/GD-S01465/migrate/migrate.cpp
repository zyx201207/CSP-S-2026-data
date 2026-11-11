#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005];
ll f[2000005];
ll cnt[2000005];
int n;
ll d;
ll solve(int st){
	ll ans=0;
	for(int i=1;i<=n;i++){
		f[i]=1e9;
		cnt[i]=0;
	}	
	f[st]=0;
	cnt[st]=1;
	int l=st;
	for(int i=st+1;i<=n;i++){
		while(a[i]-a[l]>d) l++;
		if(l==i) break;
		f[i]=f[l]+1;
		for(int j=l;j<=i&&f[j]==f[l];j++){
			cnt[i]+=cnt[j];
			if(cnt[i]>2) break; 
		}
		if(cnt[i]==2) ans++;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			ans+=solve(i);
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
} 
