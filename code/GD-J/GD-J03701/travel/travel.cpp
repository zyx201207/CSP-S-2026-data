#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1,a2,b1,b2,n,m;
	a1 = (c1[0] - '0')*10 + (c1[1] - '0');
	a2 = (c2[0] - '0')*10 + (c2[1] - '0');
	b1 = (s1[0] - '0')*10 + (s1[1] - '0');
	b2 = (s2[0] - '0')*10 + (s2[1] - '0');
	if(a1 != a2){
		cout << "0000";
		return 0;
	}else if(b1 != b2){
		cout << "1000";
		return 0;
	}else if(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C'){
		if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C'){
			if(s2[2] == 'A' && s1[2] == 'C'){
				cout <<"1110";
				return 0;
			}else if(s2[2] == 'C' && s1[2] == 'A'){
				cout << "1110";
				return 0;
			}else if(s1[2] == 'B'||s2[2] == 'B'){
				cout << "1111";
				return 0;
			}
		}
	}else if(s1[2] == 'F' || s1[2] == 'D'){
		if(s2[2] == 'F'||s2[2] == 'D'){
			cout << "1111";
		}
	}else{
		cout << "1100";
		return 0;
	}
}

