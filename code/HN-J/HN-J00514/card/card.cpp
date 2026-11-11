/*
~~小Z没长脑子吗，这都算不出来，活着干嘛~~

骗你的，其实这题我也不会了。。。痛失AK。。。 

我常常追忆过去

不过这题部分分竟然有60~80，爽吃 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(5e5 + 10)
Hahaha I AK IOI
int vis[N], q[N], edd[N], d[N], t[N];
int a[N], ans[N], n, m, ed;

void work(){
	cin >> n >> m;
	bool flA = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < a[i - 1]){
			flA = 0;
		}
	}
	if(n <= 5e3){
		for(int i = 1; i <= n; i++){
			ed = 0;
			for(int j = 1; j <= m; j++){
				vis[j] = 0;
			}
			for(int j = i; j <= n; j++){
				if(vis[a[j]] == j){
					vis[a[j]] = 0;
				}
				if(vis[a[j]] && vis[a[j]] < j){
					ed = edd[a[j]];
				}else{
					q[++ed] = a[j];
					vis[a[j]] = j;
					edd[a[j]] = ed;
				}
			} 
			for(int j = 1; j <= ed; j++){
//				cout << i << " " << q[j] << "\n"; 
				ans[q[j]]++;
				q[j] = edd[j] = 0;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i];
			if(i < m){
				cout << " ";
			}
		}
	}else if(flA){
		d[1]++;
		int l = 1;
		for(int i = 2; i <= n; i++){
			if(a[i - 1] != a[i]){
				l++;
			}
			d[l]++;
		}
		for(int i = 1; i <= m; i++){
			d[i] += d[i - 1];
			cout << d[i];
			if(i != m){
				cout << " ";
			}
		}
	}else{
		for(int i = n; i >= 1; i--){
			t[a[i]] = (t[a[i]] ? t[a[i]] : i);
		}
		for(int i = 1; i <= n; i++){
			int id = i;
			while(1){
//				cout << id << "\n";
				if(id > n){
					break;
				}
				ans[a[id]]++;
				id = t[a[id]] + 1;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i];
			if(i < m){
				cout << " ";
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int oT_To = 1;
//	cin >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
