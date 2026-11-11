#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int a;
	int c;
	string b;
	string d;
	cin >> a >> b >> c >> d;
	if(a == c) {
		cout << 1;
		if(b == d) {
			cout << 1;
			if(b in "A","B","C" and b in "A","B","C" or b in "D","F" and d in "D","F" ) {
				cout << 1; 
				if(b + 1 == d) {
					cout << 1;
				}
				else {
					cout << 0;
				}
			}
			else {
				cout << 0 << 0;
			}
		}
		else {
			cout << 0 << 0 << 0;
		}
	}
	else {
		cout << 0 << 0 << 0 << 0;
	}
	




	fclose(stdin);
	fclose(stdout);
	return 0;
}



