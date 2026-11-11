#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,sum,cnt;
long long m,a[50005],c[50005];

long long check(long long num){
	memset(c,0,sizeof(c));
	sum = 0,cnt = 0;
	for (int i = 1;i <= n;i++){
		c[i] = abs(a[i]-num);
	}
	sort(c+1,c+n+1);
	for (int i = 1;i <= n;i++){
		if (sum+c[i] <= m){
			sum += c[i];
			cnt++;
		}
	}
	return cnt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i < n;i++){
		if (ans <= check(a[i+1])){
			ans = check(a[i+1]);
		}
		else break;
	}
	cout << ans;
}
