#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1, s1, c2, s2;
bool fa, fb, fc, fd;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) fa = 1;
	if(fa && s1[0] == s2[0] && s1[1] == s2[1]) fb = 1;
	if(fa && fb){
		if((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')){
			fc = 1;
		}
	}
	if(fa && fb && fc){
		if(s1[2] >= 'A' && s1[2] <= 'C'){
			if(abs(s1[2] - s2[2]) == 1) fd = 1;
		}
		else if(s1[2] == 'D' || s1[2] == 'F'){
			if(abs(s1[2] - s2[2]) == 2) fd = 1;
		}
	}
	
	cout << fa << fb << fc << fd; 
	return 0;
}

