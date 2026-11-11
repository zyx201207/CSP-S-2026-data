#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
string s{""};int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++){
		char b;ll a;
		cin >> a >> b ;
		while(a--){
			s+=b;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++,r--;
	}
	cout << ans ;
	return 0;
}
