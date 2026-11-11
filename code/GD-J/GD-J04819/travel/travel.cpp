#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1 = 0,b1 = 0,a2,b2;
	a1 = (c1[0] - '0') * 10 + c1[1] - '0';
	b1 = (c2[0] - '0') * 10 + c2[1] - '0';
	a2 = (s1[0] - '0') * 10 + s1[1] - '0';
	b2 = (s2[0] - '0') * 10 + s2[1] - '0';	
	if(a1 == b1){
		if(a2 == b2){
			if(((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F'))){
				if(abs(s1[2] - s2[2]) == 1){
					cout << "1111";
				} else cout << "1110";
			} else cout << "1100";
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
