#include<bits/stdc++.h>
#define Year2026 ios::sync_with_stdio(0);
#define October cin.tie(0),
#define thirtyone cout.tie(0);
using namespace std;
string c1,c2,s1,s2;
bool ce(){
	bool ss1,ss2;
	ss1 = 0,ss2 = 0;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') ss1 = 1;
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') ss2 = 1;
	return ss1 == ss2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Year2026 October thirtyone
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)cout << "0000";
	else{
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			cout << ce();
			if(ce()){
				if(abs(int(s1[2]) - int(s2[2])) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F')){
					cout << 1;
				}else cout << 0;
			}else cout << 0;
		}else cout << "000";
	}
	return 0;
} 
