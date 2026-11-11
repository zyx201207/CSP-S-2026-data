#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N],ans;
int check(int x){
	int cnt = 0;
	while(x){
		if(x & 1)cnt ++;
		x >>= 1;
	}
	return cnt;
}
bool cmp(int x,int y){
	int tx = check(x),ty = check(y);
	if(tx != ty)return tx > ty;
	else return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	ans = a[1];
	for(int i = 2;i <= m;i ++){
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
