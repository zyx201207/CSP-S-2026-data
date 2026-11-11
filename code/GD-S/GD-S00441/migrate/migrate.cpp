#include <bits/stdc++.h>
#define int long long
using namespace std;
bool Mbe;
const int N =2e6+34;
int c,t;
int X[N];
unordered_map<int,int> mp;
struct node{
	int x,y;
}p[N];
void solve(){
	int n,d; cin >> n >> d;
	int top = 0;
	for (int i = 1; i <= n;i++) cin >> X[i];
	for (int i = 2; i <= n-1;i++){
		if (X[i] - X[i-1] > d || (X[i+1] - X[i]) > d)  mp[i]=1;
	}
	for (int i = 1; i <= n;i++){
		for (int j =i+1; j<=n;j++){
			if (llabs(X[i]-X[j]) <= d || mp[i] == 1 || mp[j]==1) continue;
			p[++top]={i,j};
		}
	}
	int cnt = 0;
	for (int i= 1; i <= top;i++){
		
		int lst = i;
		
		int dis = X[p[i].y] - X[p[i].x];
		int tmp = dis / d;
		if (tmp * d == dis) continue;
//		int delta = dis - tmp* d;
		if ((d-1) * 2 < dis) cnt++;
		
//		for (int k = p[i].x, k <= p[i].y;k++){
//			if (X[k] - X[lst] > d){
//				lst = k-1;
//				cnt++;
//			}
//		}
//		cnt+=1; // min_dis
//		
//		for (int l = p[i].x; l<= p[i].y-1;l++){
//			for (int r = l+1, r <= p[i].y;r++){
//				
//			}
//		}
	}
	cout << cnt << '\n';

	
	
	
}
bool Med;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
//	cerr << "Mem: " << (&Mbe - &Med) / 1048576.0 << '\n';
	cin >> c >> t;
	while (t--) solve();
	
//	cerr << "Time: " << (double)(clock() *1.0 / CLOCKS_PER_SEC) <<'\n';
	return 0;
}
