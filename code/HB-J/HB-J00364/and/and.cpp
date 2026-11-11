#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000005;
ll a[MAXN],dp[MAXN];
ll n,m;

string ttt(ll x){
	string res="";
	while(x>0){
		res+=(x%2+'0');
		x/=2;
	}
	reverse(res.begin(),res.end());
	return res;
}
ll tento(string s){
	reverse(s.begin(),s.end());
	ll cnt=0;
	for(size_t i=0;i<s.size();i++){
		if(s[i]=='1')cnt+=(ll)pow(2,i);
	}
	return cnt;
}
ll yu(ll x, ll y){
	string xa=ttt(x);
	string xb=ttt(y);
	string h="";
	size_t sa=xa.size();
	size_t sb=xb.size();
	size_t sab=min(sa,sb);
	if(sa>sb){
		reverse(xa.begin(),xa.end());
	}
	else if(sb<sa) reverse(xb.begin(),xb.end());
	for(size_t i=0;i<sab;i++){
		h+=" ";
	}
	// cout << xa << " " << xb << " ";
	for(size_t i=0;i<sab;i++){
		if(xa[i]=='1' && xb[i]=='1')h[i]='1';
		else h[i]='0';
	}
	// cout << h;
	return tento(h);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=n;j>=i;j--){
			dp[j]=max(dp[j-1],yu(a[i],a[i+1]));
		}
	}
	// for(int i=1;i<=n;i++)cout << dp[i] << " ";
	cout << dp[n];
	
	
	
	//~ cout << ttt(3) << " " << ttt(12) << " ";
	return 0;
}
