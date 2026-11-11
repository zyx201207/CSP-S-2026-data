#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 101;
int n,m,a[N],maxn = -1,ans;
bool cmp(int x,int y){
	return x > y;
}
signed main(){
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n,cmp);
	ans = a[1];
	for(int i=1;i<=m;i++){
		ans = a[i] & ans;
	}
	cout << ans;
	return 0;
}
