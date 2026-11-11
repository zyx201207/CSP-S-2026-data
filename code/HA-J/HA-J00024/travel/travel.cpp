#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool is(){
	if(s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')) return 1;
	if(s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) return 1;
	if(s1[2] == 'C' && (s2[2] == 'A' || s2[2] == 'B')) return 1;
	if(s1[2] == 'D' && s2[2] == 'F') return 1;
	if(s1[2] == 'F' && s2[2] == 'D') return 1;
	return 0;
}
bool _is(){
	if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A')) return 1;
	if((s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C')) return 1;
	if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && is()) cout << 1;
	else cout << 0;	
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && is() && _is()) cout << 1;
	else cout << 0;
	return 0;
} 
