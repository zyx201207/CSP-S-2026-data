#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a>> b >>c >> d;
	if (a[0] != c[0] || a[1] != c[1]){
		cout << 0<<0<<0<<0;
	}else{
		cout << 1;
		if(b[0] != d[0] || b[1] != d[1]){
			cout << 0<<0<<0;
		}else{
			cout << 1;
			if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C'){
				if(d[2] != 'A' && d[2] != 'B' && d[2] != 'C'){
					cout << 0<<0;
				}else{
					cout << 1;
					if (d[2] == b[2]+1 || d[2] = b[2]-1){
						cout << 1;
					}else{
						cout << 0;
					}
				}
			}else{
				if(d[2] != 'E' && d[2] != 'F'){
					cout << 0<< 0;
				}else{
					cout << 1<< 1;
				}
			}
		}
	}
	return 0;
}
