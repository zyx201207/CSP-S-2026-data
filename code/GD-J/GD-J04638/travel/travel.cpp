#include<bits/stdc++.h>
using namespace std;
struct ticket{
	string train;
	string seat;
};
ticket a,b;
bool check1() { return a.train == b.train; }
bool check2(){
	for(int i = 0; i < 2; i++){
		if(a.seat[i] != b.seat[i]) return false;
	}
	return true;
}
bool check3(){
	char x = a.seat[2];
	char y = b.seat[2];
	if(x <= 'C' && y <= 'C'){
		return true;
	}else 
		return false;	
}
bool check4(){
	char x = a.seat[2];
	char y = b.seat[2];
	if(abs(x-y) == 1) return true;
	else return false;
}
void solve(){
	if(check1()) cout << "1";
	else cout << "0";
	if(check2() && check1()) cout << "1";
	else cout << "0";
	if(check3() && check2() && check1()) cout << "1";
	else cout << "0"; 
	if(check4() && check3() && check2() && check1()) cout << "1";
	else cout << "0"; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a.train >> a.seat >> b.train >> b.seat;
	solve();
	return 0;
}
