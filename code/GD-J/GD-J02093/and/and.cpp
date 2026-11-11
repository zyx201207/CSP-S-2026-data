#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5+10;
queue<int> q;

int get(int x){
	for(int i=29;i>=0;i--)
		if((x>>i)&1)
			return i;
	return -1;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,maxn = -1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x;
		maxn = max(get(x),maxn);
		q.push(x);
	}
	for(int i=29;i>=0;i--){
		int cnt = 0,k = q.size();
		for(int j=1;j<=k;j++){
			if((q.front()>>i)&1)
				cnt++;
			q.push(q.front()),q.pop();
		}
		if(cnt<m)
			continue;
		for(int j=1;j<=k;j++){
			if((q.front()>>i)&1)
				q.push(q.front());
			q.pop();
		}
	} 
	int ans = (1<<30)-1;
	while(q.size()){
		ans &= q.front();
		q.pop();
	}
	cout << ans;
	return 0;
}
