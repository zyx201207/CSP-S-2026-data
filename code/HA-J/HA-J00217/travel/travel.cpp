#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
string s1,s2,t1,t2;
void solve(){
	cin >> s1 >> t1 >> s2 >> t2;
	if(s1!=s2){
		cout << "0000";
	}
	else{
		cout << 1;
		if(t1[0]==t2[0]&&t1[1]==t2[1]){
			cout << 1;
			char a=t1[2],b=t2[2];
			if(a>b)swap(a,b);
			if(a=='D'&&b=='F'){
				cout << 11;
			}
			else if(a=='A'&&b=='B'){
				cout << 11;
			}
			else if(a=='A'&&b=='C'){
				cout << 10;
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _T=1;//cin >> _T;
	while(_T--){
		solve();
	}
	return 0;
}
