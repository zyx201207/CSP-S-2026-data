#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 5e5 + 10; 
int n, m;
int a[N];
int fl[N], ans[N];
int mp[N], pre[N];
signed main(){
	fin("card.in");
	fout("card.out");
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]]++;
	} 
	for(int i = 1; i <= m; i++) pre[i] = pre[i - 1] + mp[i];
	if(n >= 5000){
		for(int i = 1; i <= m; i++) cout << pre[i] << ' ';
		return 0;
	}
	for(int i = 1; i <= n; i++){
		stack<int> q;
		for(int j = i; j <= n; j++){
			if(fl[a[j]]){
				while(q.top() != a[j]){
					fl[q.top()]--;
					q.pop();
				}
			}else{
				q.push(a[j]);
				fl[a[j]]++;
			}
		}
		for(int j = 1; j <= m; j++){
			if(fl[j]) ans[j]++;
			fl[j] = 0;
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
//11:35 暴力打完了 
//11:47 性质A打完了 
//估分100+65+100+40=305
