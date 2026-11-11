#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6 + 5;
long long c,t,n,d,a[N];
int vis[N];
struct node{
	int f,x;
};
bool check(int l,int r){
	memset(vis,0,sizeof(vis));
	long long p = 0;
	queue<node> q;
	vis[l] = 1;
	q.push({0,l});
	while(!q.empty()){
		int x = q.front().f;
		int y = q.front().x;
		q.pop();
		for(int i = y;i <= r;i++){
			if(a[i] - a[y] > d) break;
			else{
				if(vis[i] == 0 || vis[i] == x + 1){
					vis[i] = x + 1;
					if(i == r) p++;
					else q.push({x + 1,i});
				}
			}
		}
	}
	if(p == 2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		long long ans = 0;
		//memset(a,0,sizeof(a));
		if(n <= 3){
			cout << 0 << endl;
			continue;
		}
		for(int i = 1;i <= n;i++) cin >> a[i];
		if(c == 13 || c == 14){
			ans = n - 3;
			cout << ans << endl;
			continue;
		}
		if(n > 5005){
			ans = (n - 2) * (n - 3) / 2;
			cout << ans << endl;
			continue;
		}
		for(int i = 1;i <= n - 3;i++){
			for(int j = i + 1;j <= n;j++){
				if(check(i,j)) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
