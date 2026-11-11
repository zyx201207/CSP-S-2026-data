//GZ-S00254 游子乐 贵阳市第三中学 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5+5;
ll n,m,a[N],macnt = INT_MIN;
queue<ll> q;
bool vis[N];

void bfs(){
	q.push(n);
	while(!q.empty()){
		ll t = m,cnt = 1;
		ll h = q.front();
		vis[h] = 1;
		q.pop();
		for(int i = h;i >= 1;i--){
			if(!vis[i] && t >= a[h] - a[i]){
				t -= (a[h] - a[i]);
				q.push(i);
				cnt++;
			}
		}
		macnt = max(macnt,cnt);
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	bfs();
	cout << macnt;
	return 0;
}
