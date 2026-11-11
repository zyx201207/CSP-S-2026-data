#include<bits/stdc++.h>
using namespace std;
const int maxn = 500010;
long long a[maxn],s[maxn];
int n;
long long m;
bool check(){
	for(int i = 3;i <= n;i++){
		if(a[i] - a[i - 1] != a[2] - a[1]) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	if(check()) sort(a + 1,a + n + 1);
	//小数据(测试点1-9)
	if(n <= 5000){
		int ret = 0;
		for(int i = 1;i <= n;i++){
			int cnt = 1;
			long long sum = 0;
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				if(a[j] <= a[i]){
					sum += a[i] - a[j];
					cnt++;
				}
				if(sum <= m) ret = max(ret,cnt);
				else{
					sum = 0;
					cnt = 1;
				}
			}
		}
		cout << ret << '\n';
	}
	else{
		int ret = 0;
		for(int i = 1;i <= n;i++){
			long long cnt = 1LL * (i - 1) * a[i] - s[i - 1];
			if(cnt <= m) ret = i;
		}
		cout << ret << '\n';
	}
	return 0;
}
