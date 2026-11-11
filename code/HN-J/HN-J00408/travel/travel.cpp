#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1 , s1 , c2 , s2;
int lie1;
char hang1;
int lie2;
char hang2;
signed main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000\n";
		return 0;
	}
	else{
		for(int i = 0 ; i < 2 ; i ++){
			lie1 = lie1 * 10 + (s1[i] - '0');
		}
		hang1 = s1[2];
		for(int i = 0 ; i < 2 ; i ++){
			lie2 = lie2 * 10 + (s2[i] - '0');
		}
		hang2 = s2[2];
		if(lie1 == lie2){
			if((hang1 <= 'C' && hang2 <= 'C') || (hang1 > 'C' && hang1 <= 'F' && hang2 > 'C' && hang2 <= 'F')){
				if(abs(hang1 - hang2) == 1){
					if(hang1 == 'C' && hang2 == 'D') cout << "1110\n";
					else if(hang1 == 'D' && hang2 == 'C') cout << "1110\n";
					else  cout << "1111\n";
					return 0;
				}
				else{
					cout << "1110\n";
					return 0;
				}
			}
			else{
				cout << "1100\n";
				return 0;
			}
		}
		else{
			cout << "1000\n";
			return 0;
		}
	}
	return 0;
}
/*
02 01C 02 01A

02 01C 02 01D

02 02B 02 01A

02 01A 03 01A 
*/
