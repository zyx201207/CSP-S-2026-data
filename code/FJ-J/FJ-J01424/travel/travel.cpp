#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1, s1;//R
string c2, s2;//X
bool f1 = false, f2 = false;
int main(){
//	/*
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	*/
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		f1 = true;
	}else{
		cout << 0;
	} 
	if(s1[0] == s2[0] && s1[1] == s2[1] && f1){
		cout << 1;
		f2 = true;
	}else{
		cout << 0;
	} 
	if(((s1[2] == 'A' && s2[2] == 'B')
	|| (s1[2] == 'A' && s2[2] == 'C')
	|| (s1[2] == 'B' && s2[2] == 'A')
	|| (s1[2] == 'B' && s2[2] == 'C')
	|| (s1[2] == 'C' && s2[2] == 'A')
	|| (s1[2] == 'C' && s2[2] == 'B')
	|| (s1[2] == 'D' && s2[2] == 'F')
	|| (s1[2] == 'F' && s2[2] == 'D')) && f1 && f2){
		cout << 1;
	}else{
		cout << 0;
	}
	if(((s1[2] == 'A' && s2[2] == 'B')
	|| (s1[2] == 'B' && s2[2] == 'C')
	|| (s1[2] == 'C' && s2[2] == 'B')
	|| (s1[2] == 'D' && s2[2] == 'F')
	|| (s1[2] == 'F' && s2[2] == 'D')) && f1 && f2){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
//¹À·Ö£º100·Ö
