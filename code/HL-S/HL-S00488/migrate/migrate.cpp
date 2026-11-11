#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,d,x,y,z,ans,a[10005],g[1005][1005];
struct node{
	int v,w;
};


int main(){

freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
	ans=0;
	memset(g,0,sizeof(g));
	memset(a,0,sizeof(a));
	queue<node>q;
	vector<int>v[1005];
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				v[i].push_back(j);
		}else{
			break;
		}
	}}
	for(int i=1;i<=n;i++){
		q.push({i,0});
while(!q.empty()){
	node t=q.front();
	q.pop();
	g[t.v][t.w]++;
	for(auto k:v[t.v]){
		q.push({k,t.w++});
	}
}
	}
	

for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(g[i][j]<2){
		}else if(g[i][j]==2){
			ans++;
		}else{
			break;
		}
	}
}
cout<<ans<<'\n';
}

return 0;
}
