#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s1x,s1y,s2x,s2y;
ll a,b,c,d,f;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1x >> s1y >> s2x >> s2y;
	if(s1x == s2x) a = 1;
	for(int i = 0; i < 2; i++){
		if(s1y[i] == s2y[i]) f++;
	}
	if(f) b=1;
	if(('A' <= s1y[2] <= 'C' && 'A' <= s2y[2] <= 'C') || ('D' <= s1y[2] <= 'E' && 'D' <= s2y[2] <= 'E')) c=1;
	f=0;
	if(s1y[2] + 1 == s2x[2] || s1x[2] + 1 == s2y[2]){
		if((s1y[2] == 'C' && s1x[2] == 'D') || (s1y[2] == 'D' && s1x[2] == 'C')) f=1;
	}
	if(!f) d=1;
	cout << a << b << c << d;
	return 0;
} 
