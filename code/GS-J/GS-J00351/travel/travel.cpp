#include <bits/stdc++.h>
using namespace std;
string co,ct,so,st;
string c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> co  >> ct >> so >> st;
	bool x = true,y = true;
	for (int i = 0;i <= 1;i++){
        if (co[i] != so[i]){
            x = false;
        }
        if (ct[i] != st[i]){
            y = false;
        }
        c[i] = ct[i],s[i] = st[i];
	}
	if (x){
        cout << 1;
        if (y){
            cout << 1;
            if ( (ct[2]-'A' <= 2 && st[2]-'A' <= 2) || (ct[2] == 'D' && st[2] == 'F') || (ct[2] == 'F' && st[2] == 'D') ){
                 cout << 1;
	        }
	        else {
                cout << 0;
	        }
	    }
	    else{
            cout << 0 << 0;
	    }
	}
	else{
        cout << 0 << 0 << 0;
	}
	bool z = false;
	if (x){
        if (y){
            if ( (ct[2] == 'A' && st[2] == 'B') || (ct[2] == 'B' && st[2] == 'A') || (ct[2] == 'B' && st[2] == 'C') || (ct[2] == 'C' && st[2] == 'B') || (ct[2] == 'F' && st[2] == 'D') || (ct[2] == 'D' && st[2] == 'F') ){
                z = true;
            }
        }
	}
	if (z){
        cout << 1;
	}
	else {
        cout << 0;
	}
	return 0;
}
