#include<bits/stdc++.h>
using namespace std;
#define int long long
#define itn int
#define inl inline
#define re register
#define pos ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define N 200010
//这我真无力了
//正解想不出来 
int n;
string s;
bool huiwen(string s){
	if(s.size()==1) return true;
	for(re int l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r]) return false;
	}
	return true;
}
signed main(){
	freopen("r","string.in",stdin);
	freopen("W","string.out",stdout);
	pos;
	cin>>n;
	for(re int i=1;i<=n;i++){
		char c;
		int ai;
		cin>>ai>>c;
		for(re int j=1;j<=ai;j++){
			s+=c;
		}
	}
	if(huiwen(s)){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(re int i=0;i<s.size()/2;i++){
		if(s[i]!=s[n-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
