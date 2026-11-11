#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n, m, a[maxn];
int ans[maxn], last[maxn];
bool ins[maxn], vis[maxn];
int memo[maxn][maxn];
/*void out(stack <int> s){
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	return ;
}*/
void add(int idex){
	for(int i=1;i<=m;i++){
		ans[i]+=memo[idex][i];
	}
	return ;
}
void solve(int k){
	stack <int> s;
	memset(ins, false, sizeof(ins));
	for(int i=k;i<=n;i++){
		if(ins[a[i]]){
			while(s.top()!=a[i])s.pop();
		}else{
			s.push(a[i]);
			ins[a[i]]=true;
		}
//		out(s);
	}
	int cnt[maxn];
	for(int i=1;i<=m;i++){
		cnt[i]=ans[i];
	}
	while(!s.empty()){
		ans[s.top()]++;
		s.pop();
	}
	for(int i=1;i<=m;i++){
		memo[k][i]=ans[i]-cnt[i];
	}
	vis[k]=true;
//	cout << '\n';
	return ;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!vis[last[i]])solve(last[i]);
		else add(last[i]);
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}
