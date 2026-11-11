#include <bits/stdc++.h>
using namespace std;
int ans[300005],a[500005],n,m;
bool is_in(int now,deque<int> q){
	while(!q.empty()){
		if(q.back() == now) return 1;
		q.pop_back();
	}
	return 0;
}
void game(){
	for (int x = 1; x <= n; x++){
		deque<int>q;
		for (int i = x; i <= n; i++){
			int now = a[i];
			if(is_in(now,q)){
				while(q.back() != now){
					q.pop_back();
				}
			}else{
				q.push_back(now);
			}
		}
		while(!q.empty()){
			int num = q.front();
			ans[num]++;
			q.pop_front();
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	game();
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

