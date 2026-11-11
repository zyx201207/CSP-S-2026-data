#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=5e5+5;
int n,m;
int a[kMaxN];
int ans[kMaxN];
int vis[kMaxN];
stack<int>s;
void solve(int l){
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=l;i<=n;i++){
		if(vis[a[i]]==1){
			while(s.top()!=a[i]){
				vis[s.top()]=0;
				s.pop();
			}
			s.pop();
		}
		s.push(a[i]);
		vis[a[i]]=1;
	}
	while(!s.empty()){
		if(s.top()<=m)ans[s.top()]++;
		s.pop();
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
