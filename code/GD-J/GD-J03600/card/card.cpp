#include <bits/stdc++.h>
using namespace  std;
const int N = 5e5 + 10,M = 3e5 + 10;
int n,m,arr[N],num[N];
queue <int> q;
queue <int> check(int x){
	queue <int> p;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		if (u != x) p.push(u);
		else if (u == x) break;
	}
	return p;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	for (int i = 1;i <= n;i++){
		while(!q.empty()) q.pop();
		q.push(arr[i]);
		for (int j = i + 1;j <= n;j++){
			q = check(arr[j]);
			q.push(arr[j]);
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			num[u]++;
		}
	}
	for (int i = 1;i <= m;i++) cout << num[i] << " ";
	return 0;
}
