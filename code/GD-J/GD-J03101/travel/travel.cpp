#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll c1,s1,c2,s2;
char s1_,s2_;
void solve(){
	cin >> c1 >> s1 >> s1_ >> c2 >> s2 >> s2_;
	if(c1==c2){
		cout << 1;
		if(s1==s2){
			cout << 1;
			if(s1_<'D'&&s2_<'D'){
				cout << 1;
				if(abs(s1_-s2_)==1)cout << 1;
				else cout << 0;
			}
			else if(s1_>='D'&&s2_>='D'){
				cout << 11;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
