#include<bits/stdc++.h>
#define int long long
#define uint unsigned int
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
const int maxN = 2e5 + 5;
const int maxA = inf;
int n; int a; int le = 0;
int cnt = 0;
char c;
string s = "";
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> a >> c; le += a;
		for(int i=0;i<a;i++) s = s+c;
	}for(int i=0;i<(le+1)/2;i++){
		if(s[i] != s[le-i-1]) cnt++;
	}cout << cnt;
	return 0;
}
