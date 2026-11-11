//中央民族大学附属中学贵阳学校 夏宇森 GZ-J00504
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int x1, x2;
	string h1, h2;
	cin >> x1 >> h1 >> x2 >> h2;
	if(x1 == x2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	if(h1[0]==h2[0] && h1[1]==h2[1]){
		cout << "1";
		if(h1[2]=='A'||h1[2]=='B'||h1[2]=='C'){
			if(h2[2]=='A'||h2[2]=='B'||h2[2]=='C'){
				cout << "1";
			}
			else{
				cout << "00";
				return 0; 
			}
		}
		else if(h1[2]=='D'||h1[2]=='F'){
			if(h2[2]=='D'||h2[2]=='F'){
				cout << "11";
				return 0;
			}
			else{
				cout << "00";
				return 0; 
			}
		}
	}
	else{
		cout << "000";
		return 0;
	}
	if(abs(h1[2]-h2[2]) == 1) cout << "1";
	else cout << "0";
	return 0;
} 
