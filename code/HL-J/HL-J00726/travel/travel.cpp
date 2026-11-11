#include<bits/stdc++.h>
using namespace std;

string c1,s1;
string c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> c1 >> s1;
	cin >> c2 >> s2;
	
	if(c1 == c2){
		cout << 1;
		string str1 = "",str2 = "";
		str1 += s1[0] + s1[1],str2 = s2[0] + s2[1];
		if(str1 == str2){
			cout << 1;
			int flag1 = 0,flag2 = 0;
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
				flag1 = 0;
			}
			else{
				flag1 = 1;
			}
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
				flag2 = 0;
			}
			else{
				flag2 = 1;
			}
			if(flag1 == flag2){
				cout << 1;
				char ch1 = s1[2],ch2 = s2[2];
				if((ch1 == 'C' && ch2 == 'D') || (ch1 == 'D' && ch2 == 'C')){
					cout << 0;
					return 0;
				}
				if( ((int)abs(int(ch1 - ch2)) == 1) || (ch1 == 'D' && ch2 == 'F') || (ch1 == 'F' && ch2 == 'D') ){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	
	return 0;
}