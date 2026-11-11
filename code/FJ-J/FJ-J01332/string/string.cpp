#include<bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int max_ai = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		max_ai = max(max_ai,a[i]);
	}
	//小数据 
	if(n <= 10 && max_ai <= 50){
		string s;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= a[i];j++){
				s += c[i];
			}
		}
		int ret = 0;
		for(int i = 0;i < s.size() / 2;i++){
			if(s[i] != s[s.size() - i - 1]){
				ret++;
			}
		}
		cout << ret << '\n';
	}
	//大数据 
	else{
		int l = 1,r = n;
		int diff = 0,last = -1;
		long long ret = 0;
		while(l <= r){
			char c1 = c[l];
			char c2 = c[r];
			int cnt1 = a[l];
			int cnt2 = a[r];
			if(c1 != c2){
				ret += min(cnt1,cnt2);
				if(cnt1 > cnt2){
					r--;
					a[l] -= cnt2;
				}
				else if(cnt1 < cnt2){
					l++;
					a[r] -= cnt1;
				}
				else{
					l++;
					r--;
				}
			}
			else{
				if(cnt1 > cnt2){
					r--;
					a[l] -= cnt2;
				}
				else if(cnt1 < cnt2){
					l++;
					a[r] -= cnt1;
				}
				else{
					l++;
					r--;
				}
			}
		}
		cout << ret << '\n';
	}
	return 0;
}
