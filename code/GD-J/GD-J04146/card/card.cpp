#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005, MAXM = 300005;
int n, m, a[MAXN], sum[MAXM], s[MAXM], maxx;
bool xxxxx[MAXM];
bool used[MAXM];
queue<int> q;
map<int, int> mp;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[a[i]]++;
		maxx = max(maxx, a[i]);
		if(flag) flag = !xxxxx[a[i]];
		xxxxx[a[i]] = 1;
	}
	if(flag){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= maxx;j++){
				if(s[j]) sum[j]++;
			}
			s[a[i]]--;
		}
	}
	
	else for(int i = 1;i <= n;i++){
		memset(used, 0, sizeof(used));
		for(int j = i + 1;j <= n;j++){
			if(!used[a[j]]){
				q.push(a[j]);
				used[a[j]] = 1;
				mp[a[j]] = j;
			}
			else{
				for(int k = 1;k <= j - mp[a[j]];k++){
					used[q.front()] = 0;
//					cout << q.front() << " ";
					q.pop();
				}
			} 
		}
		while(!q.empty()){
			sum[q.front()]++;
			q.pop();
		} 
	}
	for(int i = 1;i <= m;i++) cout << sum[i] << " ";
	return 0;
}
