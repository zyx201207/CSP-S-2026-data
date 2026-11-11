#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2){
		cout << 1;
		int s=1;
		for (int i=1;i<=2;i++){
			if (s1[i]!=s2[i]){
				s=0;
			}
		}
		if (s==0){
		cout << 0 << 0 << 0;
		}
		else {
		cout << 1;
			if (s1[3]=='D' && s1[3]=='E'){
				if (s2[3]=='D' && s1[3]=='E'){
					cout << 1;
					if (s1[3]-1==s2[3] || s1[3]+1==s2[3]){
						cout << 1;
					}
				}
				else {
					cout << 0;
					cout << 0;
				}
			}
			else {
				if (s2[3]>='A' && s1[3]<='C'){
					cout << 1;
					if (s1[3]-1==s2[3] || s1[3]+1==s2[3]){
						cout << 1 ;
					}
				}
				else {
					cout << 0;
					cout << 0;
				}
			}
		}
	}
	else {
		cout << 0;
		cout << 0 << 0 << 0;
	}
	
	return 0;
}
