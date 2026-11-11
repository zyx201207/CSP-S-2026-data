#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s >> m >> t;
	if(n!=m){
		cout << "0000";
		return 0;
	}
	if(s[1]==t[1]&&s[0]==t[0]){
		if((s[2]=='D'||s[2]=='F')&&(t[2]=='A'||t[2]=='B'||t[2]=='C')){
			cout << "1100";
			return 0;
		}else if((t[2]=='D'||t[2]=='F')&&(s[2]=='A'||s[2]=='B'||s[2]=='C')){
			cout << "1100";
			return 0;
		}
		if(t[2]+1==s[2]||s[2]+1==t[2]){
			cout << "1111";
			return 0;
		}else{
			cout << "1110";
			return 0;
		}
	}else{
		cout << "1000";
		return 0;
	}
	return 0;
} 
