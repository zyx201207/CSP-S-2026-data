#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,nums[maxn],ans = 0,l = 0;
string s[maxn],s1[maxn];
signed main(){
	freopen("string,in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1){
		cout << 0;
		goto end;
	}
	for(int i = 1;i <= n;i ++){
		int x;
		string y;
		cin >> x >> y;
		nums[i] = x;
		s[i] = y;
		l += x;
	}
	for(int i = 1;i <= n;i ++){
		int n = 0;
		n += nums[i];
		for(int j = 1;j <= n;j ++){
			s1[j] = s[i];
//			cout << s1[j] << " ";
		}
	}
	if(l % 2 == 0){
		for(int i = 1;i <= l / 2;i ++){
//			cout << s1[3] << " " << s1[4] << " ";
			if(s1[i] != s1[l - i + 1])
				ans ++;
		}
	}
	else if(l % 2 != 0){
//		cout << s1[1] << s1[2] << s1[3] << s1[4] << s1[5] << " ";
		for(int i = 1;i <= l / 2;i ++){
			if(s1[i] != s1[l - i + 1]){
//				cout << s1[4] << " ";
				ans ++;
			}
		}
	}
	cout << ans;
	end:
	return 0;
} 
