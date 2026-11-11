#include<bits/stdc++.h>
using namespace std;
bool a[7891];
string c1, c2, s1, s2;
int main() {
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	a['A'] = a['B'] = a['C'] = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout<<1;
		if(s1.substr(0, 2) == s2.substr(0, 2)){
			cout<<1;
			if(a[s1[2]] == a[s2[2]])cout<<1<< (abs(s1[2] - s2[2]) == 1);
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
