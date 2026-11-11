#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn = 5e5 + 5;
const int maxm = 3e5 + 5;
inline ll read(){
	ll x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
int n,m,cur,nxt,pre,pos;
ll temp;
ll a[maxn],ans[maxm];
vector<int> g[maxm]; // g[i]::点数为i的牌出现的位置 
inline void solve(int rounds){ // 不会做，直接大模拟启动，准备TLE 
	pos = rounds;
	vector<int> cnt(m + 5,0); // cnt[i]代表i被扫描到几次 
	while(pos <= n){
		cur = a[pos],cnt[cur]++,nxt = -1;
		if(g[cur].size() >= cnt[cur]){
			nxt = g[cur][cnt[cur] - 1];
		}
		//cnt[cur]++;
		if(nxt != -1) pos = nxt;
		else{
			ans[cur]++;
			pos++;
		}
		//printf("%d的下一次出现位置为%d\n",cur,g[cur][nxt] );
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		g[a[i]].push_back(i);
	}
	for(int rounds = 1;rounds <= n;rounds++){
		solve(rounds);
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
