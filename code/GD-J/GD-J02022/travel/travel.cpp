#include <bits/stdc++.h>
using namespace std;

struct travel{
	string a = "";
	string b = "";
	string c = "";
};
travel person[5];

int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);

	string a = "" , b = "";
	for(int i = 0;i < 2;i++){
		cin >> a >> b;
		person[i].a = a;
		person[i].b = b[0,1];
		person[i].c = b[2];
	}
	if(person[0].a == person[1].a){
		cout << 1;
		if(person[0].b == person[1].b){
			cout << 1;
			if(person[0].c <= "C" && person[1].c <= "C"){
				cout << 1;
				if(person[0].c == "B" || person[1].c == "B"){
					cout << 1;
				}
				else cout << 0;
			}
			else if(person[0].c >= "D" && person[1].c >= "D"){
				cout << 11;
			}
			
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	return 0;
}
