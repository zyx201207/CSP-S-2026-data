#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
	}else{
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			a = (char)s1[2] - 64;
			b = (char)s2[2] - 64;
			if((a <= 3 && b <= 3) || (a >= 4 && b >= 4)){
				cout << 1;
				if((max(a,b) - min(a,b) == 1)){
					cout << 1;
				}else cout << 0;
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}
	return 0;
}
