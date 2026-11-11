#include<bits/stdc++.h>
using namespace std;
long long n,m,r,A;
long long ans = 1;
long long a[500010];
long long s[500010];
long long c(int x){
	for(int i = 1;i <= n;i++){
		s[i] = abs(x - a[i]);
	}
	sort(s + 1,s + n + 1);
	int sum = 0,cnt = 0;
	for(int i = 1;i <= n;i++){
		if(sum + abs(s[i]) > m || cnt == n)break;
		sum += abs(s[i]);
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(n == 1){
		cout << "1";
		return 0;
	}
	long long l = 1,r = -1000000;	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		r = max(r,a[i]);
		if(a[i] != i)A = 1;
	}
	if(A == 0){
		long long sum = 0;
		for(int i = 2;i <= n;i++){
			if(sum + i - 1 > m)break;
			ans++;
			sum = sum + i - 1; 
		} 
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= r;i++){
		if(ans == n)break;
		ans = max(ans,c(i));
	}
	cout << ans;
	return 0;
}
