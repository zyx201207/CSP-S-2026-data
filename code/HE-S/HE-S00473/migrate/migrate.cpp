#include <bits/stdc++.h>
using namespace std;
//struct node{
//	int x,cnt;
//};
int n,ans,c,t;
int sum[2000005];
long long d;
long long a[2000005];
vector<int> pass[2000005];
void dfs(){
	for(int i = 1;i <= n;i++){
		memset(sum,0,sizeof(sum));
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(u!=i) sum[u]++;
			for(int j=0;j<pass[i].size();j++){
				q.push(pass[i][j]);
			}
		}
		for(int j = 1;j < i;j++){
			if(sum[i]==2)ans++;
		}
	}
}
void solve(){
	cin >> n >> d;
	for(int i = 1;i < n;i++){
		cin >> a[i];
//		long long dis=a[i];
//		for(int j = i-1;j >= 1;j--){
//			if(dis<=d)pass[i].push_back(j);
//			else break;
//			dis+=a[j];
//		}
	}
//	dfs();
	cout << n-1 << "\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}

