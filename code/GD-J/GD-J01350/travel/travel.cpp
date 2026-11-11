#include<bits/stdc++.h>
using namespace std;
bool check(char x, char y){
	if(x >= 'A' && x <= 'C'){
		if(y >= 'A' && y <= 'C')
			return true;
	}else{
		if(y == 'D' || y == 'F'){
			return true;
		}
	}
	return false;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1 != x1){
		cout << "0000";
		return 0;
	}else if(!(r2[0] == x2[0] && r2[1] == x2[1])){
		cout << "1000";
		return 0;
	}else if(!check(r2[2],x2[2])){
		cout << "1100";
		return 0;
	}else if((!(abs(r2[2] - x2[2]) == 1)) && (r2[2]!= 'D' && r2[2] != 'F')){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
} 
