#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,cnt;
const ll N=2e5+10;
struct node{
	ll num;
	char c;
}a[N];
void solve(){
	ll ans=0;
	string s;
	for(ll i=1;i<=cnt;i++){
		for(ll j=1;j<=a[i].num;j++) s+=a[i].c;
	}
	for(ll i=0;i<ll(s.size())/2;i++){
		if(s[i]!=s[ll(s.size())-i-1]) ans++;
	}
	cout<<ans;
}
void solve2(){
	ll i=1,j=cnt,ans=0,cum=0;
	while(i<j){
		if(a[i].c!=a[j].c){
			if(a[i].num==a[j].num) cum=a[i].num;
			else cum=abs(a[i].num-a[j].num);
			ans+=min(a[i].num,a[j].num);
			if(a[i].num>a[j].num){a[i].num=cum; j--;}
			else if(a[i].num<a[j].num){a[j].num=cum;i++;}
			else {a[i].num=a[j].num=0; i++; j--;}
		}else {
			cum=abs(a[i].num-a[j].num);
			if(a[i].num==a[j].num){i++;j--;}
			else if(a[i].num<a[j].num){a[j].num=cum;i++;}
			else  {a[i].num=cum; j--;}
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&t);
	ll maxn=0;
	while(t--){
		ll n; char s;
		scanf("%lld",&n);
		cin>>s;
		maxn=max(maxn,n);
		a[++cnt].num=n;
		a[cnt].c=s;
	}
	if(maxn<=50) solve();
	else solve2();
	return 0;
}
