#include<bits/stdc++.h>
using namespace std;
long long a[200022];
bool cmp(long long a, long long b){
	return a > b;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];
	return 0;
}
