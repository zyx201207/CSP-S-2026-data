#include <bits/stdc++.h>
using namespace std;
bool q[5];
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string a , b , c , d;
	cin >> a >> b >> c >> d;
	if(a == c){
		q[1] = true;
		if(b[0] == d[0]&&b[1] == d[1]){
			q[2] = true;
			if((b[2] >= 'D'&&d[2] >= 'D')||(b[2] <= 'C'&&d[2] <= 'C')){
				q[3] = true;
				if(abs(b[2] - d[2]) == 1){
					q[4] = true;
				}
			}
		}
	}
	for(int i = 1;i <= 4;i++){
		if(q[i]){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	return 0;
}
