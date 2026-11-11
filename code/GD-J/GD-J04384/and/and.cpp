#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+1;
int a[maxn];
int ans[maxn]; 
int cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans[0] = a[1];
	for(int i = 1;i <= m;i++){
		ans[i] =( a[i] & ans[i-1]);
	}
	cout << ans[m];
	return 0;
} 

