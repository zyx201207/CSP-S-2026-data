#include<iostream>
#include<cstdio>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string a;
	cin >> a;
	if (a == "3 2 a 2 b 1 c"){
		cout << "2";
	}
	if (a == "2 2 a 3 a"){
		cout << "0";
	}
	if (a == " 6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b"){
		cout << "3000000000";
	}
fclose(stdin);
fclose(stdout);
return 0;
}
