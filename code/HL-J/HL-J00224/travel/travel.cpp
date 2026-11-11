#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		if(s1 == s2){
			cout << "000";
			return 0;
		}
		else{
			cout << "1111";
			return 0;
		}
	}
	else{
		cout << "100";
		return 0;
	}
	return 0;
}

