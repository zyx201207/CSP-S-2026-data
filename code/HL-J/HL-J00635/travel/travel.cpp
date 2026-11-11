#include<bits/stdc++.h>
using namespace std;
string c[3], s[3];
int t1, t2, t3, t4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for(int i = 1; i <= 2; i++){
		cin >> c[i] >> s[i];
	}
	if(c[1] == c[2] && c[1] != "01" && c[1] != "16"){
		t1 = 1;
		if(s[1][1] == s[2][1]){
			t2 = 1;
			if(s[1][1] == s[2][1]){
				t3 = 1;
				if(s[1][1] == s[2][1]){
				    t4 = 1;
				}
				else{
					t4 = 0;
				}
			}
			else{
				t3 = 0;
				t4 = 0;
			}
		}
		else{
			t2 = 0;
			t3 = 0;
			t4 = 0;
		}
	}
	else{
		t1 = 0;
		t2 = 0;
		t3 = 0;
		t4 = 0;
	}
	cout << t1 << t2 << t3 << t4;
	return 0;
}
