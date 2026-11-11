#include <bits/stdc++.h>
using namespace std;
int a[10003][10003];
int c,t,n,k,ans=1e9;
bool f[3000];
bool b[3000];
queue <int> q,q1;
void unit(){
	for(int i=0;i<=n;i++){
		f[i]=0;
	} 
}
void unit1(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=0;
		}
	}
}
bool check(){
	vector<int> g;
	vector<int> h;
	for(int i=1;i<=n;i++){
		if(b[i]){
			if(g.empty()){
				g.push_back(i);
			}else{
				for(int j=0;j<=g.size();j++){
					if(j==g.size()){
						if(h.empty()){
							h.push_back(i);
						}else{
							for(int l=0;l<=h.size();l++){
								if(l==h.size()){
									return 1;
								}
								if(a[h[l]][i]==1){
									h.push_back(i);
									break;
								}
							}
						}
						break;
					}
					if(a[g[j]][i]==1){
						g.push_back(i);
						break;
					}
				}
			}
		}
	}
	return 0;
}
int bfs(){
	int sum=0;
	while(1){
		if(!q.empty()){
			sum++;
			while(!q.empty()){
				int x=q.front();
				for(int i=1;i<=n;i++){
					if(f[i]||a[x][i]==0){
						continue;
					}
					f[i]=1;
					q1.push(i);
				}
				q.pop();
			}
			swap(q,q1);
		}else{
			if(check()){
				return 1e9;
			}
			return sum;
		}
	}
}
void pre(int x,int s){
	if(x>n){
		return;
	}
	if(s==k){
		unit();
		for(int i=1;i<=n;i++){
			if(b[i]){
				f[i]=1;
				for(int j=1;j<=n;j++){
					if(b[j]==1||f[j]||a[i][j]==0){
						continue;
					}
					q.push(j);
					f[j]=1;
				}
			}
		}
		ans=min(ans,bfs());
		return;
	}
	pre(x+1,s);
	b[x]=1;
	pre(x+1,s+1);
	b[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		unit1();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;
		}
		if(k>=n){
			cout<<0<<endl;
			continue;
		}
		pre(1,0);
		cout<<ans<<endl;
		ans=1e9;
	}
	return 0;
}
