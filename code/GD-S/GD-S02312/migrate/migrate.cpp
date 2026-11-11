#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long ans,a[2000005];
struct Node{
	long long id,cnt;
};
struct Node1{
	long long cnt,val;
	Node1(){
		cnt = 0;
		val = 0x3f3f3f3f;
	}
}wy[2000005];
void bfs(int x){
	queue<Node> q;
	q.push({x,0});
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(int i = u.id + 1;i <= n;i++){
			if(a[i] - a[u.id] > d){
				break;
			}
			if(u.cnt + 1 < wy[i].val){
				wy[i].val = u.cnt + 1;
				wy[i].cnt = 1;
			}else if(u.cnt + 1 == wy[i].val){
				wy[i].cnt++;
			}
			q.push({i,u.cnt + 1});
		}
	}
	for(int i = x + 1;i <= n;i++){
		if(wy[i].cnt == 2){
			ans++;
		}
		wy[i].cnt = 0;
		wy[i].val = 0x3f3f3f3f;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++){
			bfs(i);
		}
		cout << ans << '\n';
	}
	return 0;
}

