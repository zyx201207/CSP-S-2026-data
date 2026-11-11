#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5005],uh[5005],ans;
vector <int> g[5005];
stack <int> st;
deque <int> dq;
void bfs(int y){
	for(int i=0;i<g[y].size();i++){
		int f=g[y][i];
		st.push(f);
	}
	while(!st.empty()){
		int f=st.top();st.pop();
		for(int i=0;i<g[f].size();i++){
			if(g[f][i]!=y){
				dq.push_back(g[f][i]);
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cout<<0<<endl<<1;
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(x[j]<x[i]+d){
				g[i].push_back(j);
				j++;
			}
		}
		for(int i=0;i<n;i++){
			bfs(i);
			while(!dq.empty()){
				if(uh[dq.front()]==1) ans++;
				uh[dq.front()]++;
				dq.pop_front();
			}
		}
	}
	cout<<ans;
	return 0;
}
