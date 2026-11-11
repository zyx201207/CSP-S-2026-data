/*
小R没长脑子吗，这都求不出来，活着干嘛 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(2e5 + 10)
Hahaha I AK IOI
bool vis[N];
int a[N];

void work(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	int cnt = 0, ans = 0;
	for(int i = 30; i >= 0; i--){
		int ct = 0;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && !((a[j] >> i) & 1)){
				ct++;
			}
		}
		if(n - cnt - ct >= m){
			ans += (1 << i);
			cnt += ct;
			for(int j = 1; j <= n; j++){
				if(!vis[j] && !((a[j] >> i) & 1)){
					vis[j] = 1;
				}
			}
		}
	} 
	cout << ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int oT_To = 1;
//	cin >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
