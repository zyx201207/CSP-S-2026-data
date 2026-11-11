#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN = 500020;
long long n, m;
long long a[MAXN];
long long ch[MAXN];
long long now, cnt, ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld", &n);
	scanf("%lld", &m);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	if(m == 0){
		for(int i = 2; i <= n; ++i){
			if(a[i] == a[i-1]) ans++;
		}
	}
	else{
		ans = 0;
		for(int i = 1; i < n; ++i){
			now = 0;
			cnt = 1;
			for(int j = 1; j <= n-i; ++j){
				ch[j] = (a[i+j] - a[i+j-1]) * j;
			}
			int p = 1;
			while(now+ch[p] <= m){
				now += ch[p];
				p++;
				cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
