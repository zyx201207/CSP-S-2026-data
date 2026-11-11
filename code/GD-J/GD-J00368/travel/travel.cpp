#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1, c2, s1, s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	string s1_p = s1.substr(0, 2);
	string s2_p = s2.substr(0, 2);
	if (s1_p == s2_p && c1 == c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && s1_p == s2_p && c1 == c2){
		cout<<1;
	}
	else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F') && s1_p == s2_p && c1 == c2){
		cout<<1;	
	}
	else{
		cout<<0;
	}
	
	if (s1[2] > s2[2]){
		if (s1[2] == 'D' && s2[2] == 'C'){
			cout<<0;
		}
		else if ((s1[2] - s2[2] == 1 || (s1[2] == 'F' && s1[2] - s2[2] == 2)) && s1_p == s2_p && c1 == c2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		if (s2[2] == 'D' && s1[2] == 'C'){
			cout<<0;
		}
		else if ((s2[2] - s1[2] == 1 || (s2[2] == 'F' && s2[2] - s1[2] == 2)) && s1_p == s2_p && c1 == c2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	
	return 0;
}
