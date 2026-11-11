#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2;
    string b1,b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 == a2) cout << 1;
    else cout << 0; 
    int s1 = b1[0] * 10 + b1[1];
    int s2 = b2[0] * 10 + b2[1];
    if (s1 == s2){
		cout << 1;
		char zw1 = b1[2];
    	char zw2 = b2[2];
    	if (zw1 == 'A'|| zw1 == 'B' || zw1 == 'C'){
        	if (zw2 == 'A' || zw2 == 'B' || zw2 == 'C') cout << 1;
        	else cout << 0;
    	}
    	else{
        	if (zw2 == 'E' || zw2 == 'F') cout << 1;
        	else cout << 0;
    	}
    	if (zw1 == 'A' && zw2 == 'B') cout << 1;
    	else if (zw1 == 'B' && (zw2 == 'A' || zw2 == 'C')) cout << 1;
    	else if (zw1 == 'C' && zw2 == 'B') cout << 1;
    	else if (zw1 == 'D' && zw2 == 'E') cout << 1;
    	else if (zw1 == 'E' && zw2 == 'D') cout << 1;
    	else cout << 0;
	}
    else cout << "000";
    return 0;
}
