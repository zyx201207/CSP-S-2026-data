#include<bits/stdc++.h>
using namespace std;
#define int long long
//怎么莫名死翘翘了
//这集神了
int n , m;
int a[200010];
bool f[200010][66];
int cnt[66];
int vis[66];
struct node{
	int id , nxt;
} q[200010];
int tot;
bool cmp(node x , node y){
	if(x.nxt != y.nxt) return x.nxt > y.nxt;
	if(a[x.id] == a[y.id]) return x.id > y.id;
	for(int j = x.nxt - 1;~ j;j --) if(f[x.id][j] != f[y.id][j] && cnt[j] >= m) return f[x.id][j] > f[y.id][j];
	return x.id > y.id;
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		for(int j = 30;~ j;j --) if((1 << j) & a[i]) f[i][j] = 1 , cnt[j] ++;
	}
	if(m == 1){
		int ans = 0;
		for(int i = 1;i <= n;i ++) ans = max(ans , a[i]);
		cout << ans;
		return 0;
	}
	if(m == n){
		int ans = (1 << 32) - 1;
		for(int i = 1;i <= n;i ++) ans = (ans & a[i]);
		cout << ans;
		return 0;
	}
	if(m == 2){
		int ans = 0;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++){
				if(i == j) continue;
				ans = max(ans , (a[i] & a[j]));
			}
		cout << ans;
		return 0;
	}
	int ans = 0;
	for(int j = 30;~ j;j --){
		if(cnt[j] < m || vis[j] == m) continue;
		if(cnt[j] == m){
			ans = 0;
			for(int i = 0;i <= 30;i ++) vis[i] = 0;
			for(int i = 1;i <= n;i ++) if(f[i][j]) for(int k = 30;~ k;k --) if(f[i][k]) vis[k] ++;
			for(int j = 30;~ j;j --) if(vis[j] == m) ans += (1 << j);
			cout << ans;
			return 0;
		}
		else{
			tot = 0;
			for(int i = 1;i <= n;i ++) if(f[i][j]) for(int k = j - 1;~ k;k --) if(!f[i][k]){q[++ tot] = {i , k};break;}
			sort(q + 1 , q + 1 + tot , cmp);
			for(int i = 0;i <= 30;i ++) vis[i] = 0;
			for(int i = 1;i <= m;i ++){
				for(int k = 30;~ k;k --)
					if(f[q[i].id][k]) vis[k] ++;
			}
			for(int j = 30;~ j;j --) if(vis[j] == m) ans += (1 << j);// , cout << j << '\n';
			cout << ans;
			return 0;
		}
	}
	return 0;
}
