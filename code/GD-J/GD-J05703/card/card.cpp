#include <bits/stdc++.h>
using namespace std;

int v[300010];
int n,m;
int f[500010],g[500010];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>g[i];
	}
	
	for(int i=1;i<=n;i++) {
		queue<int> q,p;
		memset(v,0,sizeof(v));
		int pos=i;
		while(pos<=n){
			if(v[g[pos]]==1) {
				v[g[pos]]=0;
				while(!q.empty()) {
					int cur=q.front();
					q.pop();
					if(cur==g[pos]) while(!q.empty()) q.pop();
					else p.push(cur);
				}
				while(!p.empty()) {
					int cur=p.front();
					p.pop();
					q.push(cur);
				}
			}
			q.push(g[pos]);
			v[g[pos]]=1;
			pos++;
		}
		while(!q.empty()) {
			int cur=q.front();
			q.pop();
			f[cur]++;
		}
	}
	
	for(int i=1;i<=m;i++) cout<<f[i]<<' ';
	
	return 0;
}
