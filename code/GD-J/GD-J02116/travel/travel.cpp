#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
string c1,c2,s1,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){ // 车厢不同 
		cout << "0000\n";
		return 0;
	}
	if(s1[0] != s2[0] || s1[1] != s2[1]){ // 排数不同 
		cout << "1000\n";
		return 0;
	}
	a = s1[2],b = s2[2];
	if(a > b) swap(a,b); // a小b大 
	if(!( (a <= 'C' && b <= 'C') || (a == 'D' && b == 'F') ) ){ // 座次不在一个过道 
		cout << "1100\n";
		return 0;
	}
	if(!( (a == 'D' && b == 'F') || a + 1 == b)){ // 座次不相邻 
		cout << "1110\n";
		return 0;
	}
	cout << "1111\n";
	return 0;
}
