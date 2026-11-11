#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, ans = 0, total = 0;
struct node{
	int a;
	char c;
}num[100001];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> num[i].a >> num[i].c;
		total += num[i].a;
	}
	if(total >= 1e5){
		int l = 0, r = n - 1;
		while(l < r){
			if(num[l].c != num[r].c){
				if(num[l].a == num[r].a)ans += num[l].a;
				else{
					if(num[l].a > num[r].a){
						num[l + 1].a -= num[l].a - num[r].a;
						ans += (num[l].a - num[r].a) * 2; 
					}else{
						num[r - 1].a -= num[r].a - num[l].a;
						ans += (num[r].a - num[l].a) * 2; 
					}
				}
				l++; r--;
			}
		}
		cout << ans;
		return 0;
	}
	string s = "";
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < num[i].a; ++j)s += num[i].c;
	}
	int l = 0, r = total - 1;
	while(l < r){
		if(s[l] != s[r])ans++;
		l++; r--;
	}
	cout << ans;
	return 0;
} 
