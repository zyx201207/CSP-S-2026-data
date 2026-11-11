#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,a,b,rec[N],vis[N];
vector<int>u[N];
int dfs(int x,int y){
	int z=0;
	vis[x]=1;
	for(int v:u[x]){
		if(vis[v])continue;
		z+=dfs(v,y);
		if(rec[v]>0&&rec[v]<y&&rec)rec[x]=rec[v]+1;
		else if(rec[v]==0)z++;
	}
	vis[x]=0;
	return z;
}
bool check(int x){
	if(dfs(1,x)<=k)return 1;
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			u[a].push_back(b);
			u[b].push_back(a);
		}
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
