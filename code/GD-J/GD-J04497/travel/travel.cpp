#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f = true;
	bool ff = true;
	cin >> c1 >> s1 >> c2 >> s2;
     for(int i = 0;i < 2;i++){
		if(c1[i] != c2[i]){
		 f = false;
			break;
		}
	}
	if(f) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	for(int i = 0;i < 2;i++){
		if(s1[i] != s2[i]){
		 ff = false;
			break;
		}
	}
		if(ff) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	
	if(s1[2] == 'A' && (s2[2] =='B' || s2[2] == 'C')) cout << "1";
	else if(s1[2] == 'B' && (s2[2] =='A' || s2[2] == 'C')) cout << "1";
	else if(s1[2] == 'C' && (s2[2] =='A' || s2[2] == 'B')) cout << "1";
	else if(s1[2] == 'D' && s2[2] == 'F') cout << "1";
	else if(s1[2] == 'F' && s2[2] == 'D') cout << "1";
	else cout << "0";
	
	if(s1[2] == 'A' && s2[2] == 'B') cout << "1";
	else if(s1[2] == 'B' && (s2[2] =='A' || s2[2] == 'C')) cout << "1";
	else if(s1[2] == 'C' && s2[2] == 'B') cout << "1";
	else if(s1[2] == 'D' && s2[2] == 'F') cout << "1";
	else if(s1[2] == 'F' && s2[2] == 'D') cout << "1";
	else cout << "0";
	return 0;
} 

