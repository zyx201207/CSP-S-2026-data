#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
struct s{
	long long id;
	long long cnt;
};
vector<long long> dp[500005];
long long bfs(long long start,long long end){
	queue<s> q;
	int vis[500005];
	vis[start] = 1;
	s l;
	l.cnt = 0;
	l.id = start;
	q.push(l);
	long long ans = 0;
	long long minn = 1e18;
	while(!q.empty()){
		s e = q.front();
		q.pop();
		if(e.id == end){
			minn = min(minn,e.cnt);
			if(e.cnt == minn){
				ans++;
			}
			//cout << minn << ' ' << start << ' ' << end << ' ' << e.cnt << ' '<< ans<< endl;
		}
		for(int i = 0; i < dp[e.id].size(); i++){
			if(vis[dp[e.id][i]] != 1){
				s bn;
				bn.id = dp[e.id][i];
				bn.cnt = e.cnt+1;
				q.push(bn);
			}
		}
	}
	return ans;
}
int main(){
	long long c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long ans = 0;
		long long n,d;
		cin >> n >> d;
		long long minnn = 1e18;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			minnn = min(minnn,a[i]); 
		}
		if(minnn < 0){
			for(int i = 1; i <= n; i++){
				a[i] += abs(minnn);
			}
		}
		sort(a+1,a+n+1);
		for(int i = 1; i <= n; i++){
			dp[a[i]].clear();
		}
		for(int i = 1; i <= n; i++){
			for(int j = i-1; j >= 1; j--){
				if(a[i]-a[j] <= d){
					//cout << a[i] << ' ' << a[j] << endl;
					dp[a[i]].push_back(a[j]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i] != a[j]){
				//cout << bfs(a[i],a[j]) << "a " << endl;
					if(bfs(a[i],a[j]) == 2){
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
