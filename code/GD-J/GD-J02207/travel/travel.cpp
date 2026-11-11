#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t1,t2,num1,num2;
	char c1,c2;
//	scanf("%d %d%c %d %d%c",t1,num1,c1,t2,num2,c2);
	cin >> t1 >> num1 >> c1 >> t2 >> num2 >> c2;
//	cout << t1 << ' ' << t2 << ' ' << num1 << c1 << ' ' << num2 << c2;
//	cout << (t1 == t2);
//	cout << (num1 == num2);
	if (t1 == t2){
		cout << 1;
		if (num1 == num2){
			cout << 1;
			if ((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D')){
				cout << 1;
				if (c1+1 == c2 || c2+1 == c1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
} 
