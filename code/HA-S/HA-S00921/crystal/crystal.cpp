#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+5;
ll n,m,ans=-N;
ll o[N],cha[N];
void deal(ll x){
	ll cnt=0,sum=0,maxn=-N;
	for(ll i=1;i<=n;i++){
		ll j=i;
		while(j<=n&&sum+max(x-o[j],o[j]-x)<=m){
			sum+=max(x-o[j],o[j]-x);
			cnt++;
			j++;
		}
		maxn=max(cnt,maxn);
		cnt=sum=0;
	}
	ans=max(ans,maxn);
}
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++)	cin>>o[i];
	sort(o+1,o+1+n);
	for(ll i=o[1];i<=o[n];i++)	deal(i);
	cout<<ans<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	solve();
	return 0;
}
