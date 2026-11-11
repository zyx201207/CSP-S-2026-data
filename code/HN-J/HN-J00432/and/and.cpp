#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int l,r;
int vis[100005] = {};
int two(int p){
	int sum;
	int a = 1;
	while(p != 0){
		sum += (p % 2) * a;
		p /= 2;
		a *= 10;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int maxx = -1000000;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			maxx = max(a[i],a[j]);
		}
	}
	cout << maxx;
} 
