#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int a = 0,b = 0;
	a = s1 / 10;
	b = s2 / 10;
	if (a==b||s1 != s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int x = 0,y = 0;
	x = s1 % 10;
	y = s2 % 10;
	if((x != y || 'A' >= x >= 'C' || 'A' >= y >= 'C' ) && ('D' == x || 'F' == y ) && ('F' == x ||'D' == y)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if (x == 'A'||y == 'B' && x == 'B'||y == 'C' && x == 'D'||y == 'F'){
		cout<<"1";
	}else {
		cout<<"0";
	}

	return 0;
}
