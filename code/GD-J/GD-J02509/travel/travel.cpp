#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	else {
		cout << "1";
		if(s1.substr(0,2) != s2.substr(0,2)){
			cout << "000";
			return 0;
		}
		else {
			cout << "1";
			if(((s1[2] == 'A')|(s1[2] == 'B')|(s1[2] == 'C'))^((s2[2] == 'A')|(s2[2] == 'B')|(s2[2] == 'C'))){
				cout <<"00";
				return 0;
			}
			else {
				cout<<"1";
				if(abs(s1[2]-s2[2]) == 1){
					cout << "1";
				}
				else cout << "0";
			}
		}
	}
	return 0;
}
