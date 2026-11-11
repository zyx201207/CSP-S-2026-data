#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
string n1,n2;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> n1 >> m >> n2;
	if(n == m){
		cout << "1"; 
	}else{
		cout << "0000";
		return 0;
	}
	x = n1[0]-'0',x*=10,x+=n1[1]-'0',n1 = n1[2];
	y = n2[0]-'0',y*=10,y+=n2[1]-'0',n2 = n2[2];
	if(x == y){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(n1 == "A"||n1 == "B"||n1 == "C"){
		if(n2 == "B"||n2 == "C"||n2 == "A"){
			cout << "1";
		}else{
			cout << "00";
			return 0;
		}
	}else if(n1 == "D"||n1 == "F"){
		if(n2 == "D"||n2 == "F"){
			cout << "11";
			return 0;
		}else{
			cout << "00";
			return 0;
		}
	}
	if(n1 == "B"||n2 == "B"){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
