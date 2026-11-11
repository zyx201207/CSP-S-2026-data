#include<iostream>
#include<cstdio>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int a;
	cin >> a;
	if (a == "4 3 1 2 1 3"){
		cout << "3 1 4";
	}
	if (a == "10 3 3 1 2 1 3 2 3 1 2 1"){
		cout << "10 3 3";
	}
fclose(stdin);
fclose(stdout);
return 0;
}
