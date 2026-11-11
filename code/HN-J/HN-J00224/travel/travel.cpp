#include <iostream>
using namespace std;

string c1,c2;  // 各自车厢号 
string s1,s2;  // 各自座位号 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2){
		for (int i=0;i<4;i++){
			cout << 0;
		}
		return 0;
	}
	cout << 1;
	if (s1[0] == s2[0] && s1[1] == s2[1]){
		cout << 1;
	}else{
		for (int i=0;i<3;i++){
			cout << 0;
		}
		return 0;
	}
	if (s1[2] < 'D' && s2[2] < 'D'){
		cout << 1; 
	}else if (s1[2] >= 'D' && s2[2] >= 'D'){
		cout << 1; 
	}else{
		for (int i=0;i<2;i++){
			cout << 0;
		}
		return 0;
	}
	
	if (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1){
		cout << 1;
	}else if (s1[2] >= 'D' && s2[2] >= 'D'){
		cout << 1; 
	}else{
		cout << 0;
	}
	
	
	return 0;
}
