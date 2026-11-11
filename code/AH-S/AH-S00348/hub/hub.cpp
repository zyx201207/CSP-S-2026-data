#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],ans;
vector<int> v[20];
int c[20],vis[20],col[20];
void dfss(int x,int coll){
	for(auto i:v[x])
	if(vis[i]==0&&c[i]==1){
		vis[i]=1;
		col[i]=coll;
		dfss(i,coll);
	}
}
int viss[20];
int bfs(int x){
	memset(viss,0,sizeof(viss));
	queue<int> st1,st2;
	viss[x]=1;
	st1.push(x);st2.push(0);
	while(!st1.empty()){
		int b=st1.front(),y=st2.front();
		st1.pop();st2.pop();
		for(int i : v[b])
		if(viss[i]==0){
			viss[i]=1;
			if(c[i]) return y+1;
			st1.push(i);
			st2.push(y+1);
		}
	}
	return 1e9;
}
void check(){
	memset(vis,0,sizeof(vis));
	memset(col,0,sizeof(col));
	int kua=0,now=0;
	for(int i=1;i<=n;i++)
	if(c[i]==1&&vis[i]==0){
		kua++;
		vis[i]=1;
		dfss(i,kua);
	}
	if(kua==0||kua>2) return;
	for(int i=1;i<=n;i++)
	if(vis[i]==0){
		vis[i]++;
		now=max(now,bfs(i));
	}
	ans=min(now,ans);
}
void fun(int t,int num){
	if(num>m) return;
	if(t>n){
		check();
		return;
	}
	c[t]=1;
	fun(t+1,num+1);
	c[t]=0;
	fun(t+1,num);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		for(int i=0;i<=19;i++)
		v[i].clear();
		ans=1e9;
		cin>>n>>m;
		for(int x,y,i=1;i<=n-1;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		fun(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
