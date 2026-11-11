#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c >> d;
	if(a == c){
		if(b[0] == d[0] && b[1] == d[1]){
			if((b[2] <= 'C') == (d[2] <= 'C')){
				if(abs(b[2] - d[2]) == 1){
					cout << "1111" << endl;
				}else{
					cout << "1110" << endl;
				}
			}else{
				cout << "1100" << endl;
			}
		}else{
			cout << "1000" << endl;
		}
	}else{
		cout << "0000" << endl;
	}
	return 0;
}
