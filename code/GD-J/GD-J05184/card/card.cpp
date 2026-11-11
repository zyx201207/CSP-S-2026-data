#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n,m,a[N],vis[N],ans[N];
queue<int> q;
stack<int> s,s1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i = 1;i<=n;i++){
		if(i != 1) q.pop();
		int x = q.size();
		memset(vis,0,sizeof(vis));
		for(int j = 1;j<=x;j++){
			int u = q.front();
			q.pop();
			if(vis[u] != 0){
				while(s.top() != u){
					vis[s.top()] = 0;
					s1.push(s.top());
					s.pop();
				}
				s1.push(s.top());
				s.pop();
				while(!s1.empty()){
					q.push(s1.top());
					s1.pop();
				}
			}
			s.push(u);
			vis[u] = 1;
		}
		for(int j = 1;j<=m;j++){
			ans[j] += vis[j];
		}
		while(!s.empty()){
			s1.push(s.top());
			s.pop();
		}
		while(!s1.empty()){
			q.push(s1.top());
			s1.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
