#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 150005;
const int M = 1505;
const int INF = 1e9;
const int mod = 998244353;
void work(){
	map<string, bool> mp1, mp2;
	mp1["AB"] = 1;
	mp1["BC"] = 1;
	mp1["AC"] = 1;
	mp1["BA"] = 1;
	mp1["CB"] = 1;
	mp1["CA"] = 1;
	mp1["DE"] = 1;
	mp1["ED"] = 1;
	mp2["AB"] = 1;
	mp2["BA"] = 1;
	mp2["BC"] = 1;
	mp2["CB"] = 1; 
	mp2["DE"] = 1;
	mp2["ED"] = 1;
	string s, st, t, tt;
	cin >> s >> st >> t >> tt;
	if(s == t){
		cout << "1";
	}else{
		cout << "0000";
		return ;
	}
	if(st[0] == tt[0] && st[1] == tt[1]){
		cout << "1";
	}else{
		cout << "000";
		return ;
	}
	string c = st.substr(2, 1);
	c += tt[2];
	if(mp1[c]){
		cout << "1";
	}else{
		cout << "00";
		return ;
	}
	if(mp2[c]){
		cout << "1";
	}else{
		cout << "0";
		return ;
	}
	return ;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --){
		work();
	}
	return 0;
} 
//luogu uid:910628 球上神人共赏 
