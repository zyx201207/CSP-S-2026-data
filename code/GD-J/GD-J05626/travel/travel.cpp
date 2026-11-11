#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a1,b1;
	string a2,b2;
	cin >> a >> a1 >> a2 >> b >> b1 >> b2;
	if(a2 > b2){
		string c = a2;
		a2 = b2;
		b2 = c;
	}
	if(a == b){
		cout << 1;
		if(a1 == b1){
			cout << 1;
			if((a2 == "A" && b2 == "B") || (a2 == "A" && b2 == "C") || (a2 == "B" && b2 == "C") || (a2 == "D" && b2 == "F")){
				cout << 1;
				if((a2 == "A" && b2 == "B") || (a2 == "B" && b2 == "C") || (a2 == "D" && b2 == "F")){
					cout << 1;
					return 0;
				}
				cout << 0;
				return 0;
			}
			cout << 0 << 0;
			return 0;
		}
		cout << 0 << 0 << 0;
		return 0;
	}
	cout << 0 << 0 << 0 << 0;
	return 0;
}
