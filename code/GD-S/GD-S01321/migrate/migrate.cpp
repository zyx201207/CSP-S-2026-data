#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans,answer;
void bfs(int u,int v){
	if(v==n){
		if(ans==2) answer++;
		return ;
	}
	if(a[v]-a[u]==a[u+1]-a[v-1]) ans++;
	bfs(u+1,v+1);
	bfs(u,v+1);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bfs(1,1);
		cout<<answer<<"\n";
	}
	return 0;
}
