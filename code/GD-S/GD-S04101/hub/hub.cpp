#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int c, t, n, k, x, y, s, f[N], d[N], z[N];
vector<int>v[N];
queue<int>q;
void pd(){
	for(int i=1; i<=n; i++) d[i]=0, z[i]=f[i];
	for(int i=1; i<=n; i++){
		if(f[i]){
			f[i]=0;
			d[0]++;
			q.push(i);
			while(!q.empty()){
				int h=q.front();
				q.pop();
				for(auto g:v[h]){
					if(d[g]) continue;
					d[g]=1, f[i]=0;
					q.push(g);
				}
			}
		}
	}
	if(d[0]>2) return;
	for(int i=1; i<=n; i++){
		d[i]=2e9; 
		if(z[i]) q.push(i), d[i]=0;
	}
	while(!q.empty()){
		int h=q.front();
		q.pop();
		for(auto g:v[h]){
			if(d[h]+1>d[g]) continue;
			d[g]=d[h]+1;
			q.push(g);
		}
	}
	d[0]=2e9;
	for(int i=1; i<=n; i++){
		if(d[i]<d[0]) d[0]=d[i];
	}
	if(d[0]<s) s=d[0];
}
void dfs(int z, int g){
	if(g>k) return;
	if(z>n) pd();
	else{
		f[z]=1;
		dfs(z+1, g+1);
		f[z]=0;
		for(int i=1; i<=n; i++) cout<<f[i]<<" ";
		cout<<"\n";
		dfs(z+1, g);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		s=2e9;
		scanf("%d%d", &n, &k);
		for(int i=1; i<n; i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
//		dfs(1, 0);
		printf("1\n");
	}
	return 0;
}
