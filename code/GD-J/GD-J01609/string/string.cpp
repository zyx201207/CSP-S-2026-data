#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=2*1e5+10;
constexpr ll INF=1e18;
int n;
ll a[N],sum;
char c[N];
ll Abs(ll x){
	if(x>=0) return x;
	return -x;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n<=2000){
		string t="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				t+=c[i];
			}
		}
		ll ans=0;
		int i=0,j=t.size()-1;
		while(i<=j){
			if(t[i]!=t[j]) ans++;
			i++; j--;
		}
		cout<<ans;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}

