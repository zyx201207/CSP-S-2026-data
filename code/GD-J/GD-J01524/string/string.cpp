#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n; 
long long a1[N];
string a2[N];
string s;
int ans;
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
		cin>>a2[i];
		for(int j=1;j<=a1[i];j++){
			s=s+a2[i];
		}
	}
	for(int L=0,R=s.size()-1;L<=R;L++,R--){
		if(s[L]!=s[R]){
			ans++;
		}
	}
	cout<<ans;
} 
int main(){
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}

