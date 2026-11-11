#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200006;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = "";
	long long r = 0;
	for(int i = 1; i <= n; i++){
		int tmp1;
		char tmp2;
		cin >> tmp1 >> tmp2;
		for(int j = 1; j <= tmp1; j++){
			s += tmp2;
		}
		r += tmp1;
	}
	long long ans1 = 0;
	long long l = 0,r1 = r - 1; 
	while(l < r1){
		if(s[l] != s[r]) {
			ans1++;
		}
		l++;
		r1--;
	}
	cout << ans1;
}
