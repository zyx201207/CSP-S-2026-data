#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string R1,X1;
	string R2,X2;
	cin >> R1 >> R2 >> X1 >> X2;
	int a = 0,b = 0;
	if(R2[2] - 'A' <= 2){
		if(X2[2] - 'A' <= 2){
			a = 1;
			if(R2[2] -X2[2] == 1 || R2[2] - X2[2] == -1)b = 1;
		}else a = 0;
	}else if(X2[2] - 'A' >= 3){
		a = 1;
		if(R2[2] -X2[2] == 1 || R2[2] - X2[2] == -1)b = 1;
	}
	
	if(R1 == X1)cout << 1;
	else cout << 0;
	if(R1==X1 && R2[0] == X2[0] && R2[1] == X2[1])cout << 1;
	else cout << 0;
	if(R1==X1 && R2[0] == X2[0] && R2[1] == X2[1] && a == 1)cout << 1;
	else cout << 0;
	if(R1==X1 && R2[0] == X2[0] && R2[1] == X2[1] && a == 1 && b == 1)cout << 1;
	else cout <<0;
	 
	return 0;
}
