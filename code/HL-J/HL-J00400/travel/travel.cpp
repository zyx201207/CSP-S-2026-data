#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool a1,a2,a3,a4;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    a = s1[0]+s1[1];
    b = s2[0]+s2[1];
    c = s1[2];
    d = s2[2];
    if(c1 == c2) {
    	a1 = 1;
    	if(a == b) {
    		a2 = 1;
    		if((c>67&&d>67) || (c<=67&&d<=67)) {
    			a3 = 1;
    			if((c==65&&d==66)||(c==66&&d==65)||(c==66&&d==67)||(c==67&&d==66)||(c==68&&d==70)||(c==70&&d==68)) {
    				a4 = 1;
    				cout << a1 << a2 << a3 << a4;
				}
				else {
					a4 = 0;
					cout << a1 << a2 << a3 << a4;
				}
			}
			else{
				a3 = 0;
				a4 = 0;
				cout << a1 << a2 << a3 << a4;
			}
		}
		else{
			a2 = 0;
			a3 = 0;
			a4 = 0;
			cout << a1 << a2 << a3 << a4;
		}
	}
	else {
		a1 = 0;
		a2 = 0;
		a3 = 0;
		a4 = 0;
		cout << a1 << a2 << a3 << a4;
	}
    return 0;
}
