#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n , k;
int cnt1 , ans1 = 0x7f7f7f7f , dp1[15];
vector<int> G[N];
void dfs1(int s , int u , int fat , int op){
	if(((1<<(u-1))&s) && !op){
		op = 1;
		cnt1++;
	}else if(!((1<<(u-1))&s) && op) op = 0;
//	cout << op << ' ';
	for(int v : G[u]){
		if(v == fat) continue;
		dfs1(s , v , u , op);
	}
}
int dfs11(int s , int u , int fa){
	if(!((1<<(u-1))&s)) dp1[u] = dp1[fa] + 1;
	else dp1[fa] = min(dp1[fa] , 1) , dp1[u] = 0;
	int ans = 0;
	for(int v : G[u]){
		if(v == fa) continue;
		ans = max(ans , dfs11(s , v , u));
		dp1[u] = min(dp1[u] , dp1[v]+1);
	}
	return max(ans , dp1[u]);
}
void solve1(){
//	if(n != 9) return;
	for(int i = 1;i <= n;i++){
		dp1[i] = 0x7f7f7f7f;
		ans1 = 0x7f7f7f7f;
		cnt1 = 0;
	}
	for(int i = 0;i < (1<<n);i++){
		int w = i , ct = 0 , rt;
		while(w){
			if(w & 1) ct++;
			w >>= 1;
		}
		if(ct != k) continue;
		cnt1 = 0;
		dfs1(i , 1 , 0 , 0);
//		cout << cnt1 << endl;
		if(cnt1 > 2) continue;
//		w = i;
//		while(w){
//			cout << (w&1);
//			w >>= 1;
//		}
//		cout << endl;
		for(int j = 0;j < n;j++)
			if((1<<j)&i){
				rt = j+1;
				break;
			}
		int ad;
		ans1 = min(ans1 , ad=dfs11(i , rt , 0));
//		for(int j = 1;j <= n;j++) cout << dp1[j] << ' ';
//		cout << endl;
	}
	printf("%d\n" , ans1);
//	cout << endl;
}
void mian(){
	scanf("%d%d" , &n , &k);
	int u , v;
	for(int i = 1;i < n;i++){
		scanf("%d%d" , &u , &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n <= 10) solve1();
	for(int i = 1;i <= n;i++) G[i].clear(); 
}
int main(){
	
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	
	int T;
	scanf("%d" , &T);
	scanf("%d" , &T);
	while(T--) mian();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
