#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt = 0,x = 1;
	long long ans = 0;
	cin >> n;
	string s[20005];
	for (int i = 0;i < n;i ++){
		int a;
		char c;
		cin >> a >> c;
		for (int j = 0;j < a;j ++){
			s[cnt++] = c;
		}
	}
	for (int i = 0;i < (cnt + 1) / 2;i ++){
		for (int j = cnt;j > (cnt + 1) / 2;j ++){
			if (s[i] == s[j]){
				continue;
			}
			else{
				x = 0;
				ans ++; 
			} 
		}
	}
	if (x){
		cout << 0;
	} 
	else{
		cout << ans;
	}
	return 0;
} 
