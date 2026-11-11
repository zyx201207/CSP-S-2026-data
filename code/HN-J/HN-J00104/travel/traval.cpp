#include<bits/stdc++.h>
using namespace std;
char s, s2;
int a, b, c, d; 
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin >> a >> b >> s >> c >> d >> s2;
	if(a == c){
		cout << 1;
		if(b == d){
			cout << 1;
			if((s == 'A' || s == 'B' || s == 'C' && s2 == 'A' || s2 == 'B' || s2 == 'C') || (s == 'D' || s == 'F' && s2 == 'D' || s2 == 'F')){
				cout << 1;
				if(s == 'A' && s2 == 'B' || s == 'B' && s2 == 'A' || s == 'B' && s2 == 'C' || s == 'C' && s2 == 'B' || s == 'D' && s2 == 'F' || s == 'F' && s2 == 'D' ){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	
	
	return 0;
} 
