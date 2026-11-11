#include <bits/stdc++.h> 
using namespace std; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool k;
	bool a[4];
	int b[2];
	int c1,c2;
	string s1,s2;
	int sam = 0;
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		b[0] = 1;
	}
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
		b[1] = 1;
	}
	if((s1[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B')){
		k = true;
	}
	if((s1[2] == 'B') && (s2[2] == 'C' || s2[2] == 'A')){
		k = true;
	}
	if((s2[2] == 'B') && (s1[2] == 'C' || s1[2] == 'A')){
		k = true;
	}
	if((s1[2] == 'C' && s2[2] == 'B') || (s2[2] == 'C' && s1[2] == 'B')){
		k = true;
	}
	if((s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F')){
		k = true;
	}
	if(c1 == c2){
		a[0] = true;
		if(s1[0] == s2[0]&&s1[1] == s2[1]){
			a[1] = true;
			if(b[0] == b[1]){
				a[2] = true;
				if(k == true){
					a[3] = true;
				}
			}		
		}
	}
	if(a[0] == true){
		sam += 1000;
	}
	if(a[1] == true){
		sam += 100;
	}
	if(a[2] == true){
		sam += 10;
	}
	if(a[3] == true){
		sam += 1;
	}
	cout << sam;
	return 0; 
}
