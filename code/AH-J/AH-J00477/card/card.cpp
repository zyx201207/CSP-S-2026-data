#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10,M=3e5+10;
ll n,m,a[N],f[N];
ll ans[M],pre[M];
bool flag[M];
void AC(){
	ll cnt=0;
	ans[a[n]]=n;
	for(ll i=1;i<=n;i++) if(a[i]!=a[n]) cnt++;
	if(a[n]==1) a[2]=cnt;
	else a[1]=cnt;
	cout<<a[1]<<' '<<a[2];
}
void solve(){
	for(ll k=1;k<=n;k++){
		memset(flag,false,sizeof flag);
		ll p=0;
		for(ll i=k;i<=n;i++){
			if(flag[a[i]])
				while(p>0&&f[p]!=a[i]) p--;
			else{
				flag[a[i]]=true;
				f[++p]=a[i];
			}
		}
		for(ll i=1;i<=p;i++) ans[f[i]]++;
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
}
int main(){
	flag[0]=true;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==2){
		AC();
		return 0;
	}
	if(n<=5000&&m<=3000){
		solve();
		return 0;
	}
	for(ll i=1;i<=m;i++) pre[i]=n+1;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i>=1;i--){
		flag[a[i]]=true;
		if(i>=pre[a[i]]) continue;
		ll p=i;
		while(p){
			p--;
			if(flag[a[p]]&&a[p]!=a[i]) break;
		}
		ans[a[i]]+=i-p;
		pre[a[i]]=p+1;
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
 	return 0;
}
