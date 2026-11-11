#include<bits/stdc++.h>
#define ll long long
using namespace std;

	ll f[5010][5010];
	ll cnt[5010][5010];
	ll a[2000010];
	ll n,d,ans;
ll abss(ll x){
	if(x<0)return -x;
	return x;
}
void hi(ll q){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>a[i];
	
	if(q==11||q==12){
		ll k=abss(a[2]-a[1]);
		if(k>=d){cout<<"0\n";return;}
		if(k%d==0){cout<<n-k/d-1<<"\n";return;}
		else {cout<<n-k/d-2<<"\n";return;}
	}
	
	
	
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++){
			if(i==j)f[i][j]=0;
			else{
				cnt[i][j]=0;
				if(abss(a[i]-a[j])<=d){
					f[i][j]=1;
					f[j][i]=1;
					cnt[i][j]=1;
					cnt[j][i]=1;
				}else{
					f[i][j]=0x3f3f3f3f3f3fLL;
					f[j][i]=0x3f3f3f3f3f3fLL;
				}
			}
		}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			if(i==k)continue;
			for(ll j=1;j<=n;j++){
				if(j==k||i==j)continue;
				if(f[i][j]==f[i][k]+f[k][j]){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}else if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
			}
		}
	}
	ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)hi(c);
	return 0;
}
//T3
//csp-s 2026 RP++!
