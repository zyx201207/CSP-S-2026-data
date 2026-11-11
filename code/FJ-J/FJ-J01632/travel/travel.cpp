#include<bits/stdc++.h>
#define int long long
using namespace std;
string c[2],s[2];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c[0] >> s[0] >> c[1] >> s[1];
	if(c[0]!=c[1]) cout<<"0000";
	else{
		cout<<"1";
		if(s[0][0]!=s[1][0] || s[0][1]!=s[1][1]){
			cout<<"000";
		}
		else{
			cout<<"1";
			if((s[0][2]<='C')^(s[1][2]<='C')){
				cout<<"00";
			}
			else{
				cout<<"1";
				if(s[0][2]>='D') cout<<"1";
				else if(s[0][2]!='B' && s[1][2]!='B'){
					cout<<"0";
				}
				else cout<<"1";
			}
		}
	}
	return 0;
}

