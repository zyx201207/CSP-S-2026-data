//travel
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string c,s,c_,s_;//小R 的车票上的车厢号、座位号，以及小X 的车票上的车厢号、座位号。

void solve(){
	cin >> c >> s >> c_ >> s_;
	if(c==c_)cout << 1;
	else{
		cout << "0000";
		return ;
	}
	ll ss = (s[0]-'0')*10+(s[1]-'0');
	ll ss_ = (s_[0]-'0')*10+(s_[1]-'0');
	if(ss==ss_)cout << 1;
	else{
		cout << "000";
		return ;
	}
	if(s[2]>='A'&&s[2]<='C'){
		if(s_[2]>='A'&&s_[2]<='C')cout << 1;
		else{
			cout << "00";
			return ;
		}
	}
	else{
		if(s_[2]>='D'&&s_[2]<='E')cout << 1;
		else{
			cout << "00";
			return ;
		}
	}
	
	if( (s[2]=='A'&&s_[2]=='B') || (s_[2]=='A'&&s[2]=='B') || (s[2]=='B'&&s_[2]=='C') || (s_[2]=='B'&&s[2]=='C') || (s[2]=='D'&&s_[2]=='E') || (s_[2]=='D'&&s[2]=='E') )cout << 1;
	else cout << 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
} 
