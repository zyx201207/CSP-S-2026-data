#include<bits/stdc++.h>
typedef  long long  ll;
using namespace std;
struct C{
	ll a;
	char c;
};
ll n=1,cnt=0,ans=0;
vector<char> a,b,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll o;
		char p;
		cin>>o>>p;
		for(ll i=1;i<=o;i++)a.push_back(p);
		cnt+=o;
	}
	ll cnt2=cnt/2;
	if(cnt%2==1){
		
		for(ll i=0;i<=cnt2;i++){
			b.push_back(a[i]);
		}
		for(ll i=cnt-1;i>=cnt2;i--){
			c.push_back(a[i]);
		}
		
	}
	else if(cnt%2==0){
		for(ll i=0;i<=cnt2-1;i++){
			b.push_back(a[i]);
		}
		for(ll i=cnt-1;i>=cnt2;i--){
			c.push_back(a[i]);
		}
		cnt2-=1;
	}
	for(ll i=0;i<=cnt2;i++){
		if(b[i]!=c[i])ans++;
	}
	cout<<ans;
	return 0;
}
