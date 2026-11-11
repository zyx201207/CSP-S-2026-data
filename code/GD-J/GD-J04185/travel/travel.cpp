#include <bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c >> s1 >> s2 >> s;
	if (c1 == s1){
		cout << 1;
		if (c2 == s2){
			cout << 1;
			if ((s < 'D' && c < 'D') || (s > 'C' && c > 'C')){
				cout << 1;
				if (s + 1 == c || s - 1 == c){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << 0;
				cout << 0;
			}
		}
		else{
			cout << 0;
			cout << 0;
			cout << 0;
		}
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
}
