#include <bits/stdc++.h>
using namespace std;

#define int long long

int cx1,id1,cx2,id2;
char c1,c2,c;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin >> cx1 >> c;
	id1 = c - '0';
	cin >> c >> c1;
	id1 = id1 * 10 + c - '0';
	
	cin >> cx2 >> c;
	id2 = c - '0';
	cin >> c >> c2;
	id2 = id2 * 10 + c - '0';
	
	cout << (cx1 == cx2);
	cout << (cx1 == cx2 && id1 == id2);
	cout << (cx1 == cx2 && id1 == id2 && ((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D')));
	cout << (cx1 == cx2 && id1 == id2 && abs(c1 - c2) == 1 && !((c1 == 'C' && c2 == 'D') || (c1 == 'D' && c2 == 'C')));
	return 0;
} 
