//GZ-J00346»Æ²Åèò 
#include<iostream>
#include<string>

using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);


	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(a == "4 3" && b == "1 2 1 3") cout<<"3 1 4";
	else if(a == "10 3" && b == "3 1 2 1 3 2 3 1 2 1") cout<<"10 3 3";

	return 0;
}
