#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int n,m,a[MAXN],big = -1;
bool flag[MAXN],flaga = 1;

bool cmp(int x,int y){
	return x > y;
}

void dfs(int c,int sums){
	if(c > m){
		big = max(big,sums);
		return;
	}
	for(int i=1 ; i<=n ; i++){
		if(flag[i]) continue;
		flag[i] = 1;
		if(sums == -1) dfs(c+1,a[i]);
		else dfs(c+1,sums&a[i]);
		flag[i] = 0;
	}
}

void z2jz(int s){
	if(s == 0) return;
	z2jz(s/2);
	if(s%2 == 0) flaga = 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
		z2jz(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m == 1){
		cout << a[1];
		return 0;
	}
	if(m == 2){
		int big = -1;
		for(int i=1 ; i<=n-1 ; i++){
			for(int j=i+1 ; j<=n ; j++){
				big = max(big,a[i]&a[j]);
			}
		}
		cout << big;
		return 0;
	}
	if(m == n){
		int cnt = a[1];
		for(int i=2 ; i<=n ; i++) cnt &= a[i];
		return 0;
	}
	if(flaga){
		cout << a[m];
		return 0;
	}
	dfs(1,-1);
	cout << big;
	return 0;
}
