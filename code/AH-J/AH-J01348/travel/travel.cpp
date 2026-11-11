#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	char x = s1[2], y = s2[2];
	if(c1 == c2) cout<<1;
	else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout<<1;
	else{
		cout<<0<<0<<0<<endl;
		return 0;
	}
	if(((x == y + 1 || x == y + 2) && x != 'D' ) || ((y == x + 1 || y == x + 2) && y != 'D') == 0){
		cout<<0<<0<<endl;
		return 0;
	}else cout<<1;
	if((x == y + 1 && x != 'D') || (y == x + 1 && y != 'D') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')){
		cout<<1<<endl;
		return 0;
	}else cout<<0<<endl;
	return 0;
}
/*
((x == 'A' && y != 'B') || (x == 'B' && (y != 'A' || y != 'C')) || (x == 'C' && y != 'B' ) || (y == 'A' && x != 'B' ) || (y == 'B' && (x != 'A' || x != 'C')) || (y == 'C' && x != 'B'))
(x == 'A' && (y != 'B' || y != 'C')) || (x == 'B' && (y != 'A' || y != 'C')) || (x == 'C' && (y != 'B' || y != 'A')) || (y == 'A' && (x != 'B' || x != 'C')) || (y == 'B' && (x != 'A' || x != 'C')) || (y == 'C' && (x != 'A' || x != 'B'))) || (x == 'D' && y != 'F') || (y == 'D' && x != 'F')
 */
