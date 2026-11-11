#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct s {
	long long x,y;
}a[200001];
void add(long long t,long long k){
	long long res = 0;
	a[t].x = k;
	while(k){
		if(k % 2 == 1){
			res++;
		}
		k /= 2;
	}
	a[t].y = res;
}
long long cmp(s i,s j){
	return i.y > j.y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		long long k;
		cin >> k;
		add(i,k);
	}
	sort(a + 1,a + n + 1,cmp);
	if(m == 1){
		ans = a[1].x;
	}else{
		ans = a[1].x & a[2].x;
		for(long long i = 3;i <= m;i++){
			ans = ans & a[i].x;
		}
	}
	cout << ans;
	return 0;
}
