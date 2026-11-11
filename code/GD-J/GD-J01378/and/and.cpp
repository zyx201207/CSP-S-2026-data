#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x, long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	long long ans = a[1];
	sort(a+1,a+n+1,cmp);
	ans = a[1];
	for(long long i = 1;i <= m;i++){
		ans = (ans & a[i]);
	}
	cout<<ans;
	
	return 0;
}
// 给到拉完了 
// 样例干的
