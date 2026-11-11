#include<bits/stdc++.h>
using namespace std;

long long n, m, a[2000005], ans=0;
void DFS(long long tn, long long tm, long long t){
	if(tm > m)return;
	if(tm == m){
		ans = max(ans, t);
		return;
	}
	if(tn == n+1){
		return;
	}
	if(n-tn+1 < m-tm) return;
	long long tt;
	if(tm == 0) tt = a[tn];
	else tt = t & a[tn]; 
	DFS(tn+1, tm+1, tt);
	if(n-tn+1 == m-tm) return;
	DFS(tn+1, tm, t);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	DFS(1, 0, 0);
	cout << ans;
	return 0;
} 
