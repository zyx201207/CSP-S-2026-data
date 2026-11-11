#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int c, T;
int n, d;
int x[N];
bool f[N];
int s[N];
int p[N];
int cnt;
int ans;
int max1 = INT_MAX;
int max2 = INT_MAX;
void dfs(int st, int ed, int sum){
	if(x[st] == x[ed]){
		if(sum < max1){
			max1 = sum;
			for(int i = 1;i < cnt;i++){
				p[i] = s[i];
			}
		}
		return ;
	}
	for(int i = st + 1;i <= ed;i++){
		if(abs(x[i] - x[st]) <= d){
			s[++cnt] = i; 
			dfs(i, ed, sum + abs(x[i] - x[st]));
			s[cnt--] = 0;
		}
	}
}
void DFS(int st, int ed, int sum){
	if(x[st] == x[ed]){
		if(sum < max2){
			max2 = sum;
		}
		return ;
	}
	for(int i = st + 1;i <= ed;i++){
		if(x[i] - x[st] <= d && !f[x[i]]){
			dfs(x[i], x[ed], sum + abs(x[i] - x[st]));
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		memset(x, 0, sizeof(x));
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){	
			for(int j = i + 1;j <= n;j++){			
				memset(f, 0, sizeof(f));		
				memset(s, 0, sizeof(s));
				memset(p, 0, sizeof(p));
				max1 = INT_MAX;
				max2 = INT_MAX;
				dfs(i, j, 0);			
				for(int k = 1;k < cnt;k++){
					f[p[k]] = 1; 
				}			
				cout << endl;
				DFS(i, j, 0);
				if(max1 == max2) ans++;
			}		
		}
		cout << ans << endl;
	}
}
