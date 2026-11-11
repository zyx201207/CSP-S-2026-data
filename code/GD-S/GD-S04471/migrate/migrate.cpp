#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[6009],sho[6009],cnt=0;
vector<long long> ch[6009];
void bfs(int i){
	int len=1;
	queue<int> q;
	q.push(a[i]);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int v:ch[p]){
		if(len<=sho[v]){
		sho[v]=len;
		q.push(v);
	}
	}
	len++;
	}
}
int dfs(int x,int y,int dep){
	if(x>y) return 0; 
	if(x==y&&dep==sho[y]) return 1;
	int res=0;
	for(int v:ch[x]){
		res+=dfs(v,y,dep+1);
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cnt=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=6002;i++) ch[i].clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) ch[i].push_back(j);
				else break; 
			}
		}
		for(int i=1;i<=n;i++){
		for(int z=1;z<=6002;z++) sho[z]=1e9;
		bfs(i);
		for(int j=i+1;j<=n;j++){
		if(dfs(i,j,0)==2) cnt++;
	}
	}
	cout<<cnt<<endl;
	}
	return 0;
}
