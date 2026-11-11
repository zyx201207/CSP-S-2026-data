#include<bits/stdc++.h>
using namespace std;
//?ios
int a[500010];
int nxt[500010];
int last[500010];
int cnt[500010];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	bool flag = 1;
	a[0] = 1919810;
	for(int i = 1;i <= n;++ i){
		cin >> a[i];
		if(a[i] > a[i - 1]) flag = 0;
	}
	if(flag){
		int i = 1;
		int nw = a[0];
		while(i <= n){
			if(i > 1 && a[i] != nw) cout << i - 1 << ' ' , nw = a[i];
			++ i;
		}
		return 0;
	}
	for(int i = 1;i <= n;++ i) nxt[i] = 1919810;
	for(int i = 1;i <= n;++ i) nxt[last[a[i]]] = i , last[a[i]] = i;
	for(int i = 1;i <= n;++ i) if(nxt[i] == i) nxt[i] = 1919810;
	for(int i = 1;i <= n;++ i){
		int j = i;
		while(j <= n){
			++ cnt[a[j]];
			while(nxt[j] != 1919810) j = nxt[j];//cout << 114514 << '\n';
			++ j;
		}
	}
	for(int i = 1;i <= m;++ i) cout << cnt[i] << ' ';
	return 0;
}
