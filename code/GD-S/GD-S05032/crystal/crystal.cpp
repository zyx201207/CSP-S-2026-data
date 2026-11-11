#include<bits/stdc++.h>
#define ll long long
const int MAXN = 50010;
using namespace std;
ll n,m,a[MAXN];
bool p = 1;
int ans;

void dfs(int x){
	
	if(x > m) return;
	if(x == m){	
		int tot = 0,tmp = 0;
		for(int i = 1;i<n;i++){
			if(i == 1 && a[1] == a[2]) tmp = 1;
			if(a[i] == a[i-1] && a[i] == a[i+1]){
				tmp++;
			}
			else if(a[i] == a[i-1] && a[i] != a[i+1]){
				tmp++;
				tot = max(tot,tmp);
			}
			else if(a[i] != a[i-1] && a[i] == a[i+1]){
				tmp = 1;
			}
		}
		ans = max(ans,tot);
		return ;
	}
	for(int i = 1;i<n;i++){
		if(a[i] != a[i+1]){
			int chaa = a[i+1] - a[i];
			a[i] = a[i+1];
			dfs(x+chaa);
			a[i] -= chaa;
		}
	}
}
/*5 5
1 2 4 8 9
5 8 
-3 -1 2 2 7
*/ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(i >= 3 && a[i] - a[i-1] != a[i-1] - a[i-2]) p = 0;
	}
	sort(a+1,a+n+1);
	
	// m大于等于总需求 
	int tot = 0;
	for(int i = n-1;i>=1;i--){
		if(i == n-1){
			tot = a[i+1] - a[i];
			continue;
		}
		else{
			tot += a[n] - a[i];
		}
	}
	if(tot <= m){
		cout << n << endl;
		return 0;
	}
	
	
	// 特殊AB
	if(p){
		int d = a[2] - a[1],zong = m;
		int jiajia = d,step = 1;
		while(1){
			if(zong - jiajia < 0){
				cout << step << endl;
				return 0;
			}
			zong -= jiajia;
			jiajia += d;
			step ++;
		}
	} 
	
	dfs(0);
	cout << ans << endl;
	return 0;
} 
