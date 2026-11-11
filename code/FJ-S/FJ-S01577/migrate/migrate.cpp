#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, nu, ans[100002], dis[2000002], x[2000002];
queue<int> q;

void bfs(int b){
	q.push(1);
	while(!q.empty()){
		nu++;
		for (int i=1;i<=n;i++){
			if (x[q.front()]+d>=x[i]){
				if (i==n && dis[i]==nu)ans[b]++;
				if (dis[i]>nu)dis[i]=nu;
				q.push(x[i]);}}
		q.pop();}}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int h=1;h<=t;h++){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> x[i];}
		bfs(h);}
	for (int i=1;i<=t;i++){
		cout << ans[i] << endl;}
	return 0;
}
