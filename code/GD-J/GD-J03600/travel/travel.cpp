#include <bits/stdc++.h>
using namespace  std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[1] == s2[1]){
		cout << 1;
		if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
			cout << 1;
		}else if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0 << 0;
	}
	int n1 = int(s1[2]),n2 = int(s2[2]);
	int u = n1 - n2;
	if (u < 0) u *= -1;
	if (u == 1 && s1[1] == s2[1]){
		if (!((s1[2] == 'D' || s1[2] == 'C') && (s2[2] == 'D' || s2[2] == 'C')))
		cout << 1;
	}else cout << 0;
	if ((s1[2] == 'D' || s1[2] == 'C') && (s2[2] == 'D' || s2[2] == 'C')) cout << 0;
	return 0;
} 
