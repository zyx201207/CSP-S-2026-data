#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[2],b = s2[2];
	int size = abs(a - b);
	string c,d;
	for(int i = 0;i <= 1;i++){
		c += s1[i];
		d += s2[i];
	}
	if(c1 == c2){
		cout << 1;
		if(c == d){
			cout << 1;
			if((a == 'A' && b == 'B' || a == 'A' && a == 'C' || a == 'B' && b == 'A' || a == 'B' && b == 'C' || a == 'C' && b == 'A' || a == 'C' && b == 'B') || (a == 'E' && b == 'F' || a == 'F' && b == 'E')){
				cout << 1;
				if(size == 1){
					cout << 1;
				}else{
					cout << "0";
					return 0; 
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}
