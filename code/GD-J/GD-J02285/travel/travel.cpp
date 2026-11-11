#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char c1,c2;
	scanf("%d %d%c %d %d%c",&a,&b,&c1,&c,&d,&c2);
	if (a!=c){
		cout << "0000";
	}
	else {
		if (b!=d){
			cout << "1000"; 
		}
		else {
			if (c1<='C'&&c2<='C'||c1>'C'&&c2>'C'){
				cout << "111";
				if (c1>c2){
					swap(c1,c2);
				}
				if (c2!=c1+1){
					cout << 0;
				}
				else {
					cout << 1;
				}
			}
			else {
				cout << "1100";
			}
		}
	}
	return 0;
}
