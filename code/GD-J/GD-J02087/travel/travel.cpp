#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<char,int> idl;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _ = 1;//cin >> _;
	while(_--){
		int a1,a2;string c1,c2;
		cin >> a1 >> c1 >> a2 >> c2;
		bool t = (a1 == a2);
		bool r = t && (c1[0] == c2[0] && c1[1] == c2[1]);
		idl['A'] = 1,idl['B'] = 2,idl['C'] = 3,idl['D'] = 7,idl['F'] = 8;
		
		int id1 = idl[c1[2]],id2 = idl[c2[2]];
		bool l = r && (abs(id1 - id2) <= 2);
		bool p = l && (abs(id1 - id2) == 1);
		cout << t << r << l << p;
	}
	return 0;
}

