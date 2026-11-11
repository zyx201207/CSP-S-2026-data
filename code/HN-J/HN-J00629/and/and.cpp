#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[200005],ans = (1<<30)-1,t[32];
bool vis[32][200005],w[32];
int lowbit(int x){
	return x & -x;
}
signed main(){
	freopen("and.in" ,"r" ,stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
		while (a[i]){
			int k = log2(lowbit(a[i]));
			t[k]++;
			a[i] -= lowbit(a[i]);
			vis[k][i] = 1;
		}
	}
	for (int i = 30;i >= 0;i--)
		if (t[i] > m){
			bool flag = 0;
			for (int j = i-1;j >= 0;j--){
				int cnt = 0;
				for (int k = 1;k <= n;k++)
					if (vis[j][k] && vis[i][k]) cnt++;
				if (cnt == m){
					for (int k = 1;k <= n;k++)
						if (vis[j][k] && vis[i][k]) ans &= b[k];
					flag = 1;
					break;
				}
			}
			if (flag) break;
			sort(a+1,a+n+1);
			int cnt = 0;
			for (int k = 1;k <= n;k++){
				if (vis[i][k]) cnt++,ans &= a[i];
				if (cnt >= m) break;
			}
			break;
		}else if (t[i] == m){
			for (int j = 1;j <= n;j++)
				if (vis[i][j]) ans &= b[j];
			break; 
		}
	cout << ans;
	return 0;
}
//Ì°ÐÄ 
