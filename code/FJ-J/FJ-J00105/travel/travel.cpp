#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;
	if (s1 == t1){
		if (s2.substr(0, 2) == t2.substr(0, 2)){
			char sc = s2[2], tc = t2[2],
			left[4] = {'A', 'B', 'C', '\0'}, right[3] = {'D', 'F', '\0'};
			bool S = 0, T = 0;
			for(int i = 0;i < 3;i++){
				if(sc == left[i]){
					S = 1;
				}if(tc == left[i]){
					T = 1;
				}
			}if(S && T){
				if(abs(sc - tc) == 1){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else if(!S && !T){
				cout << "1111";
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}return 0;
}
