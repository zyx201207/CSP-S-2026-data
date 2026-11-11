#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct pi{
	int x;
	char c;
}s[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> s[i].x >> s[i].c;
	}
	int l = 1,r = n,ans = 0;
	while(l < r){
		int d = min(s[l].x , s[r].x);
		if(s[l].c != s[r].c){
			ans += d;
		}
		s[l].x -= d;
		s[r].x -= d;
		if(s[l].x == 0)l ++;
		if(s[r].x == 0)r --;
//		cout << l << " " << r << "\n";
	}
	cout << ans;
	return 0;
}
