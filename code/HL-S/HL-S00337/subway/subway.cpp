#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,xian;
}dian[500005];
struct edge{
	int u,xian;
};
vector<int> xian[500005];
map<int,int>xianlu[505];
vector<int>bian[500005];
int ans=0,p=0;
bool pan(int a,int b){
	for(int i:xian[a]){
		for(int j:xian[b]){
			if(i=j)return true;
		}
	}
}
void dfs(int u,int fa,int mu){
	if(u==mu){
		p=1;	
		return;
	}
	for(auto i:bian[u]){
		if(i==fa)continue;
		dfs(i,u,mu);
		if(p==1){
			if(!pan(fa,i)){
				ans+=xianlu[dian[fa].xian][fa]+xianlu[dian[fa].xian][u]+xianlu[dian[i].xian][u]+xianlu[dian[i].xian][i];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c >>n >>m >>d >>q;
	for(int i=1;i<=m;i++){
		cin>>dian[i].v;
//		cout<<dian[i].v<<endl;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k; 
		int a,t;
		cin>>a >>t;
		xianlu[i][a]=t;
		xian[a].push_back(i);
		dian[a].xian=i;
		for(int j=2;j<=k;j++){
			int a1,t1;
			cin>>a1 >>t1;
			bian[a].push_back(a1);
			bian[a1].push_back(a);
			xian[a1].push_back(i);
			dian[a1].xian=i;
			xianlu[i][a1]=t1;
			a=a1;
		}
//		cout<<1<<endl;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x >>y;
		ans+=dian[x].v;
		cout<<ans<<endl;
		ans+=dian[y].v;
		cout<<ans<<endl;
		ans+=xianlu[dian[x].xian][x];
		cout<<ans<<endl;
		ans+=xianlu[dian[y].xian][y];
		cout<<ans<<endl;
		dfs(x,0,y);
		cout<<ans<<endl;
		ans=0;p=0;
	}
}
