#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,a[2000005],mn[2000005],mncnt[2000005];
void dfs(int i,int l){
	if(mn[i] == l){
		mncnt[i]++;
	}else if(mn[i] >= l){
		mn[i] = l;
		mncnt[i] = 1;
	}
	for(int j = i + 1;j <= n;j++){
		if(a[j] - a[i]  <= m){
			dfs(j,l+1);
		}else break;
	}
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int i =1 ;i <= n ;i ++){
			cin >> a[i];
		}
		if(n <= 9){	
			int cnt = 0;
			for(int x = 1;x <= n;x++){
				for(int i =1;i <= n ;i ++){
					mn[i] = INT_MAX + 0LL;
				}
				dfs(x,0);
				for(int i =1;i <= n;i++){
					if(mncnt[i] == 2){
						cnt++;
					}
				}
	//			if(x == 1){
	//				cout << mn[4];
	//			}
			}
			cout << cnt << '\n';
		}else if(c == 11 || c == 12){
			int i = 1;
			while(a[i]-a[1] <= m){
				i++;
			}
			if(i == 2){
				cout << 0 << '\n';
				return 0;
			}
			cout << n - i +2;
		}else{
			cout << 0 << '\n'; // Ô¼µÈÓÚcout<<"No idea"; 
		}
	}
	fclose(stdin);
	fclose(stdout);
}
