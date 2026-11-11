#include<bits/stdc++.h>
using namespace std;

int a[512345];
int n,m;
int lst[312345];//当前最后一个同位素
int nxt[512345];//下一个同位素，没有则为0
int nxt_cur[512345];//下一个 非0 nxt 的id，可以nxt_cur[i] = i 当nxt[i]!=-1时 ；没有则为n + 1
int d[512345];//c的差分数组
int c[512345];//个数
int ans[312345];
int dp[512345];//这一次对局的状态会被引用多少次
void solve_tmlrock() {
	for(int i = n; i>0; --i)
		if(nxt_cur[i]<=n)dp[nxt_cur[nxt[nxt_cur[i]]] ]++;
	for(int i = n; i>0; --i) {

		if(nxt_cur[i]<=n) {
//		cout<<dp[i] <<' '<<i<<nxt[nxt_cur[i]]<<nxt[i]<<endl;
			d[nxt[nxt_cur[i]]] += dp[i];
			d[nxt_cur[i]] -=dp[i];
		}
	}
	for(int i = 1; i<=n; ++i) {
		c[i] = d[i] + c[i-1];
	}
	for(int i = 1; i<=n; ++i)ans[a[i]] += c[i];
//		cout<<endl;
}
void init_tmlrock() {
	memset(lst,0,sizeof(lst));
//	memset(dp,0,sizeof(dp));
	nxt_cur[n+1] = n+1;
	for(int i = n; i>=1; --i) {
//		c[i] = i;
		dp[i] = 1;
		ans[a[i]] += i;
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
		if(nxt[i] && (nxt[i] <=n )) nxt_cur[i] = i;
		else nxt_cur[i] = nxt_cur[i+1];
//		cout<<nxt[i]<<' '<<nxt_cur[i]<<' '<<lst[a[i]]<<' '<<a[i]<<' '<<endl;
	}
}
void read_tmlrock() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n; ++i)cin>>a[i];
}
void output_tmlrock() {
	for(int i = 1; i<=m; ++i)cout<<ans[i]<<' ';
}
//void solution_tmlrock() {
////	for(int i = 1;i<=n;++i) {
////		
////	}
//}
int main() {
	read_tmlrock();
	init_tmlrock();
	solve_tmlrock();
	output_tmlrock();
	return 0;
}

