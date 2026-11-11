#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in;"r";stdin);
	freopen(travel.out;"w";stdout)
	string c1[1],s1[3],c2[1],s2[3];
	cin >> c1[1];
	cin >> s1[1] >> s1[2];
	cin >> c2[1];
	cin >> s2[1] >> s2[2];
	if(c1[1] == c2[1]){
		cout << "1";
		if(s1[1] == s2[1]){
			cout << "1";
			if(s1[3] == "C"){
				cout << "00";
			}else{
				cout << "1";
				if(s1[2]+"1"==s2[2])
				cout << "0";
			}
		}else{
			cout << "000";
	}
	}else{
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
