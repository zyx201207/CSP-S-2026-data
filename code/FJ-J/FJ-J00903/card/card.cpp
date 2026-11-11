#include<bits/stdc++.h> 
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int n,m,a[N],res[N],cnt[N],pre[N];
deque<int> dq;
vector<int> vec[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = n;i >= 1;i --){
		if(pre[a[i]]){
			vec[i] = vec[pre[a[i]]];
			cnt[pre[a[i]]] ++;
		}
		else{
			vec[i] = vec[i + 1];
			cnt[i + 1] ++;
			res[a[i]] ++;
			vec[i].push_back(i);
		}
		pre[a[i]] = i;
	}
	for(int i = 1;i <= n;i ++){
		for(int j : vec[i]){
			res[a[j]] += cnt[i];
		}
	}
	for(int i = 1;i <= m;i ++) cout << res[i] << ' ';
	return 0;
}
