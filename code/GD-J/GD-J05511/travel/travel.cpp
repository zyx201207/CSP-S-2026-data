#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int n1,m1,a;
string n2,m2;
int main(){
    freopen int("travel.in",stdin); 
	freopen(int "travel.out",stdout);
	cin >> n1 >> n2 >> m1 >> m2;
	if(n1!=m1){
		cout << "0000";
	}
	if(n2[0]!=m2[0] && n2[1]!=m2[1]){
		cout << "1000";
	}
	
	if((n2[2]==m2[2]+1)||(n2[2]==m2[2]-1)){
		if((n2[2] == 67 && m2[2] == 68)||(n2[2] == 68 && m2[2] == 67)){
			cout << "1100";
		}
		else{
			cout <<"1111";
		}
	}
	else{
		cout << "1110";
	}
	return 0;
} 
