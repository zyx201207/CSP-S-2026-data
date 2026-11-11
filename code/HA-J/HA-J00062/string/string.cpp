#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a[N],ans;
char c[N];
string st;
bool hui(string s){
	string s1=s;
	reverse(s.begin(),s.end());
	if(s==s1) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(ll j=0;j<a[i];j++){
			st+=c[i];
		}
	}
	if(hui(st)){
		cout<<0;
		return 0;
	}
	ll l=st.size();
	for(ll i=0;i<(l-1)/2;i++){
		if(st[i]!=st[l-i+1]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
26
3 h
1 j
2 l
1 s
1 d
1 i
1 f
1 j
1 d
1 s
1 f
2 n
1 c
1 s
4 j
1 s
1 d
1 f
1 d
1 s
1 k
1 l
1 k
1 d
1 s
3 l
*/
