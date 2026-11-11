#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if(c1 != c2) {cout << "0000";return 0;} 
	else cout << "1";
	
	bool f2 = true; 
	for(int i=0;i<2;i++){
		if(s1[i] != s2[i]) f2 = false;
	}
	
	cout << f2;
	
	bool f3 = false;
	if(f2 && !(s1[2] == 'C' && s2[2] == 'D') && !(s1[2] == 'D' && s2[2] == 'C')) f3 = true;
	cout << f3;
	
	cout << (f3 && (abs(s1[2] - s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')));
	
	return 0;
}
