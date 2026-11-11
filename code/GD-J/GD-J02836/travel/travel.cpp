#include<iostream> 
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	bool flag = true;
	if(s1 == s3) cout << 1;
	else{
		flag = false;
		cout << 0;
	}
	
	if(flag && s2[0] == s4[0] && s2[1] == s4[1]) cout << 1;
	else{
		flag = false;
		cout << 0;
	}
	
	char c1 = s2[2], c2 = s4[2];
	if(flag && (c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C' || c1 >= 'D' && c1 <= 'F' && c2 >= 'D' && c2 <= 'F')) cout << 1;
	else{
		flag = false;
		cout << 0;
	}

	if(flag && (c1 + 1 == c2 || c1 - 1 == c2)) cout << 1;
	else cout << 0;
	return 0;
}
