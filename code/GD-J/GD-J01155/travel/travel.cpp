#include<iostream>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		printf("0000");
		return 0; 
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		printf("1000");
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C')printf(abs(s1[2]-s2[2])==1?"1111":"1110");
	else if(s1[2]>'C'&&s2[2]>'C')printf("1110");
	else printf("1100");
	return 0;
}
