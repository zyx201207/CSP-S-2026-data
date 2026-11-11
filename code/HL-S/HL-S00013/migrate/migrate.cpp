#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=(a); i<=(b); i++)
#define rep1(i, a, b) for(int i=(a); i>=(b); i--)
#define IloveCCF ios::sync_with_stdio(0);
#define Pleasegivememorepts cin.tie(0);
#define Thankyou cout.tie(0);
const int N=2e6+5;
const int inf=INT_MAX;
struct Node{
	int mnstep, cnt;
}k;
int T;
int n, d;
int ans;
int l[N];
void dfs(int u, int t, int step){
	if (step>k.mnstep) return ;
	if (u==t) {
		if (step==k.mnstep) k.cnt++;
		else if (step<k.mnstep) k.mnstep=step, k.cnt=1;
		return ;
	}
//	cout << k.mnstep << " " << step << " " << k.cnt << '\n';
	rep1(v, t, u+1){
		if (l[v]-l[u]>d) continue;
		dfs(v, t, step+1);
	}
}
void solve(){
	ans=0;
	cin >> n >> d;
	rep(i, 1, n)
		cin >> l[i];
	rep(i, 1, n) rep(j, i+2, n){
//		cout << 1 << " ";
		k=Node{inf, 0};
		dfs(i, j, 0);//baosou gives me more power
		if (k.cnt==2) ans++;
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	IloveCCF
	Pleasegivememorepts
	Thankyou
	int gunmu;
	cin >> gunmu >> T;
	while (T--)
		solve();
	return 0;
}