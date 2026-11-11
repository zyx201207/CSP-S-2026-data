#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct node{
	int a;
	int t;
};
vector<node> k[505];
int x,y;long long ans=0;
void dfs(int xx,int yy,long long time){
	if(yy==y){
		time+=w[yy];
		if(ans>time) ans=time;
		return;
	}
	if(time>ans) return;
	if(xx==x){
		time+=w[xx];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		for(int j=0;j<kk;j++){
			int aa,tt;
			cin>>aa>>tt;
			k[i].push_back({aa,tt});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dfs(x,y,0);
		cout<<ans;
	}
}
