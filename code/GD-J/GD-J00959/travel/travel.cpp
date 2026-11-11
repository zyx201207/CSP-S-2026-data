include <bits/c++std.h> 
using namespace std;

int main(){
	freopen('travel.in' , 'r' , in)
	freopen('travel.out' , 'w' , out)
	string c1 , c2 , s1 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[1] == c2[1]){
		cout << '1';
	}
	else{
		cout << '0';
	}
	if (s1[1] == s2[1]){
		cout << '1';
		if (s1[2] >= 'D' && s2[2] >= 'D'){
			cout << "11";
		}
		else if (s1[2] - 1 == s2[2] || s2[2] - 1 == s1[2]){
			cout << "11";
		}
		else{
			cout << "10";
		}
	}
	else{
		cout << "000";
	}
	
	
	return 0;
}
