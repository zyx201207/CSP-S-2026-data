#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		if(b[0] == d[0] && b[1] == d[1]){
			cout << 1;
			int L[5] = {0,0,0,0,0};
			L[b[2] == 'F' ? 4 : b[2]-'A'] = 1;
			L[d[2] == 'F' ? 4 : d[2]-'A'] = 1;
			if(L[3] + L[4] == 2){
				cout << 11;
			}else if((L[3] + L[4]) != 1){
				cout << 1;
				if(L[2]+L[0] != 2){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
