#include<iostream>
using namespace std;
int main(){
	freopen("travel.in";"r";stdin);
	freopen("travel.out";"w";stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 = s1){
		cout << "11";
	}
	else if(c1 != c2){
		cout << "00";
	}
	int a = s1;
	int b = s2;
	if(a = b){
		cout << "11";
	}
	else{
		cout << "00";
	}
	return 0; 
}
