#include<bits/stdc++.h>
#define fs first
#define sc second
#define N 100005
//#define int long long
using namespace std;

string a1, a2, b1, b2;

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a1 >> a2 >> b1 >> b2;
	
	bool s1 = (a1 == b1);
	bool s2 = s1 & (a2.substr(0, 2) == b2.substr(0, 2));
	bool s3 = s2 & !((a2[2] <= 'C') ^ (b2[2] <= 'C'));
	bool s4 = s3 & (abs(a2[2] - b2[2]) == 1);
	
	cout << s1 << s2 << s3 << s4;
	
	return 0;
	
} 
