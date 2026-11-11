#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int maxn = 3e5 + 10;
int len[maxn];
char ch[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	int ans = 0;
	int ans1 = 0 , ans2 = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> len[i] >> ch[i];
		ans += len[i];
	}
	int l = 1 , r = n;
	int cnt = 0;
	while(ans1 < ans / 2 && ans2 < ans / 2 && l < r){
		if(len[l] < len[r]){
			ans1 += len[l];
			ans2 += len[l];
			len[r] -= len[l];
			if(ch[l] != ch[r]){
				cnt += len[l];
			}
			++l;
		}
		else if(len[l] == len[r]){
			ans1 += len[r];
			ans2 += len[r];
			len[l] -= len[r];
			if(ch[l] != ch[r]){
				cnt += len[r];
			}
			--r;
			++l;
		}
		else{
			ans1 += len[r];
			ans2 += len[r];
			len[l] -= len[r];
			if(ch[l] != ch[r]){
				cnt += len[r];
			}
			--r;
		}
	}
	cout << cnt;
	return 0;
}//Trick||Treat!
