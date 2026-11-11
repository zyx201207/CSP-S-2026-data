#include <bits/stdc++.h>
using namespace std;

int n,d;
int a[3100];

short v[3100][3100][55];
short ans[3100][3100];

void dfs(int i,int cnt,vector<int> b) {
	if(cnt > 50) return;
	for(int j = i+1,f = 0;j <= n && a[j]-a[i] <= d;j++) {		
		for(int x = 0;x < b.size();x++) {
			v[b[x]][j][b.size()-x]++;
		}
		vector<int> b_ = b;
		b_.push_back(j);
		dfs(j,cnt+1,b_);
	}	
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t; cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		
		memset(ans,0,sizeof(ans));
	
		for(int i = 1;i <= n-1;i++) {
			dfs(i,0,vector<int>(1,i));
		}
		
		int cnt = 0;
		for(int i = 1;i < n;i++) {
			for(int j = 2;j <= n;j++) {
				int k = 2;
				while(k <= 50 && v[i][j][k] == 0) k++;
				if(v[i][j][k] == 2) cnt++;
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
