//card
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N=1e5+5,M=5*N,K=5000;
int n,m;
int a[M];
bool vis[M];
int ans[M];
void solve(int x){
	stack<int> s;
	memset(vis,0,sizeof(vis));
	for(int i = x;i<=n;i++){
		if(vis[a[i]]==0) {
			s.push(a[i]);
			vis[a[i]]=1;
		} else {
			while(vis[a[i]]==1){
				vis[s.top()]=0;
				s.pop();
			}
			s.push(a[i]);
			vis[a[i]]=1;
		}
	}
	while(s.size()){
		ans[s.top()]++;
		s.pop();
	}
	return ;
}

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	
	for(int i = 1;i<=n;i++){
		solve(i);
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
