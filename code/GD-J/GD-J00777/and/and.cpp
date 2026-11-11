#include <bits/stdc++.h>
using namespace std;
int a[200005];
int t[20005];
int n , m;
int maxn = 0;
int an(int cnt){
	int js1 , js2
	for(int i = 1;i <= n;i++){
	for(int j = 1;j <= n;j++){
		if(i == j || t[a[i]] != 0 || t[a[j]] != 0)continue;
			maxn = max(maxn , a[i] & a[j]);
			js1 = a[i];
			js2 = a[j];
		}
	}
	t[js1]++;
	t[js2]++;
	if(cnt!=0)return an(m--);
	return maxn;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	an(m);
	cout << maxn;
	return 0;
}
