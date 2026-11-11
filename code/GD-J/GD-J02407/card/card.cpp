#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int ans[N];
int a[N];
int n, m;
deque<int> dq;
struct Node{
	bool flag;
	int ls;
}f[N];

bool check(int x){
	if(f[x].flag == 1) return true;
	return false;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int k = 1; k <= n; k++){
		memset(f, 0, sizeof f);
		dq.clear();
		for(int i = k; i <= n; i++){
			if(check(a[i])){
				while(dq.size() >= f[a[i]].ls){
					dq.pop_back();
				}
				dq.push_back(a[i]);
				f[a[i]].flag = 1;
				f[a[i]].ls = dq.size();
			}
			else{
				dq.push_back(a[i]);
				f[a[i]].flag = 1;
				f[a[i]].ls = dq.size();
			}
		}
		while(!dq.empty()){
			ans[dq.front()]++;
			dq.pop_front();
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

