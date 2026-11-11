#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e4 + 5;
long long n,ans = 0,m;
string s;
void fu(){
	for(int i = 0; i < m / 2; i ++ ){
		int r = 1;
		if(char(s[i]) != char(s[m - r]))ans ++;
		r ++;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	while(n --){
		long long x;
		string ans;
		cin >> x >> ans;
		while(x -- ){
			s += ans;
		}
	}
	m = s.size();
	fu();
	cout << ans;
	return 0;
}

