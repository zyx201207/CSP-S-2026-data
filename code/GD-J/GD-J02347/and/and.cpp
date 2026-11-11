#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans = 0;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		int maxn = -1;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int ans = a[1];
	for(int i = 2;i <= m;i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
