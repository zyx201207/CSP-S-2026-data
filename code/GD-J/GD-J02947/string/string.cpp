#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 9;
long long num[MAXN + 1];
char s[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long sum = 0,ans = 0;
	cin >> n;
	num[n + 1] = 0;
	for(int i = 1;i <= n;i++){
		cin >> num[i] >> s[i];
		sum += num[i];
	}
	long long l = 1,r = sum;
	int lk = 1,rk = n;
	long long suml = num[1],sumr = num[n];
	while(l <= r){
		if(s[lk] != s[rk]) ans++;
		l++,r--;
		if(l - num[lk - 1] > suml){
			lk++;
			suml += num[lk];
		}
		if(sum - r + 1 - num[rk + 1] > sumr){
			rk--;
			sumr += num[rk];
		}
	}
	cout << ans;
	return 0;
}
