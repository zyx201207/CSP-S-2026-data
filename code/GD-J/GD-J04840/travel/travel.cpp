#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r",stdin);
	freopen("travel.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans=0;
	
	if(c1==c2){
		cout << 1;
		ans++; 
	}else{
		cout << 0;
	}
	
	if(s1[0]==s2[0] && s1[1]==s2[1] && ans==1){
		cout << 1;
		ans++;
	}else{
		cout << 0;
	}
	
	if(('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C' || 'D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F') && ans==2){
		cout << 1;
		ans++;
	}else{
		cout << 0;
	}
	
	if (abs(s1[2]-s2[2]) == 1 && ans==3){
		cout << 1;
	}else{
		cout << 0;
	}
	
	
	return 0;
}
