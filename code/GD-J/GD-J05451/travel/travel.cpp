#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
set<char> a1, a2;
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	a1.insert('A');
	a1.insert('B');
	a1.insert('C');
	a2.insert('D');
	a2.insert('F');
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if(a1.count(s1[2]) && a1.count(s2[2]) || a2.count(s1[2]) && a2.count(s2[2])){
				cout << 1;
				if(s1[2] == 'D'){
					if(s2[2] == 'F') cout << 1;
					else cout << 0;
				}else if(s1[2] == 'F'){
					if(s2[2] == 'D') cout << 1;
					else cout << 0;
				}else if(s1[2] == 'A'){
					if(s2[2] == 'B') cout << 1;
					else cout << 0;
				}else if(s1[2] == 'B'){
					if(s2[2] == 'C' || s2[2] == 'A') cout << 1;
					else cout << 0;
				}else if(s1[2] == 'C'){
					if(s2[2] == 'B') cout << 1;
					else cout << 0;
				}
			}//ÎÒÌÆÍêÁË 
			else cout << "00";
		} 
		else cout << "000";
	} 
	else cout << "0000";
	
}
