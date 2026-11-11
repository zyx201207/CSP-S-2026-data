#include<bits/stdc++.h>
using namespace std;
long long n,a,slen,ans,cnt;
char d;
string s;
bool tot(){
	for(int i = 0;i < slen;i++){
		if(s[i] != s[slen-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> d;
		for(int j = 1;j <= a;j++){
			s += d;
		}
	}
	slen = s.length();
	cnt = slen / 2;
	if(tot() == true){
		cout << ans;
		return 0;
	}
	else{
		for(int i = 0;i <= cnt;i++){
			if(s[i] != s[slen-i-1]){
				ans++;
			}
		} 
	}
	cout << ans;
	
	return 0;
}
