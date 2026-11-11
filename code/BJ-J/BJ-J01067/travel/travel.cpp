#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a[5],b[5];
	string a1,s1,a2,s2;
	cin >> a1 >> s1 >> a2 >> s2;
	a[1] = (int(a1[0])-48)*10 + (int(a1[1])-48);
	a[2] = (int(s1[0])-48)*10 + (int(s1[1])-48);
	if(s1[2] == 'D'){
		a[3] = 5;
	}
	else{
		a[3] = int(s1[2])-64;
	}
	b[1] = (int(a2[0])-48)*10 + (int(a2[1])-48);
	b[2] = (int(s2[0])-48)*10 + (int(s2[1])-48);
	if(s2[2] == 'D'){
		b[3] = 5;
	}
	else{
		b[3] = int(s2[2])-64;
	}
	if(a[1] == b[1]){
        if(a[2] == b[2]){
            if(abs(a[3]-b[3]) == 1){
                cout << "1111";
            }
            else{
                cout << "1110";
            }
        }
        else{
            cout << "1000";
        }
	}
	else{
        cout << "0000";
	}
	return 0;
}