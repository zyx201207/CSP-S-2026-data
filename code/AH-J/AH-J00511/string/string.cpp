#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char> v;
ll minn=1e18,vis['z'+10];
ll L;
char ch;
void dfs(string s,ll ans){
	string ts=s;
	reverse(ts.begin(),ts.end());
	if(ts==s){
		minn=min(minn,ans);
		return ;
	}
	for(ll i=0;i<ll(s.size());i++){
		for(ll j=0;j<ll(v.size());j++){
			char tmp=s[i];
			s[i]=v[i];
			dfs(s,ans+1);
			s[i]=tmp;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	string s;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	while(n--){
		cin>>L>>ch;
		vis[ll(ch)]++;
		if(vis[ll(ch)]==1){
			v.push_back(ch);
		}
		while(L--){
			s+=ch;
		}
	}
	for(ll i=0;i<ll(v.size());i++) cout<<v[i]<<" ";
	reverse(s.begin(),s.end());
	dfs(s,0);
	cout<<minn;
	return 0;
}
