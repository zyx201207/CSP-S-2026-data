#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> f >> b >> c >> e >> d;
    
	if(a==c){
		cout << "1";
	}	
	else{
		cout << "0000";
		return 0;
	}
	if(f==e){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	if(b=="A"&&d=="B"||b=="A"&&d=="C"||b=="B"&&d=="C"||d=="A"&&b=="B"||d=="A"&&b=="C"||d=="B"&&b=="C"||b=="D"&&d=="F"||b=="F"&&d=="D"){
		cout << "1";
	}
	else{
		cout << "00";
		return 0;
	}
	if(b=="A"&&d=="B"||d=="A"&&b=="B"||b=="B"&&d=="C"||d=="B"&&b=="C"||b=="D"&&d=="F"||d=="D"&&b=="F"){
		cout << "1";
	}
	else{
		cout << "0";
	}
	return 0;
}

