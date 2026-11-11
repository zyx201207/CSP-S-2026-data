#include<bits/stdc++.h>
using namespace std;
struct {
	int at[2];
	int to;
	int from;
	int weight[2];
	int o;
}u[50001];
int n,m,d,q,c; 
int k;
int e;
int now;
int s;
int ans;
int h;
int k1;
int k2;
void find(int a,int b){
	if(u[a].from!=b){
		ans=ans+u[u[a].from].weight[1]+u[u[a].from].weight[2];
		find(u[a].from,b); 
	}
}
void find1(int a,int b){
	if(u[a].to!=b){
		ans=ans+u[u[a].to].weight[1]+u[u[a].to].weight[2];
		find(u[a].to,b); 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>u[i].o;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			u[j].from=now;
			h=now;
			cin>>now;
			u[h].to=now;
			if(u[now].weight[1]!=0){
				cin>>u[now].weight[1];
			}else{
				cin>>u[now].weight[2];
			}
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		ans=u[s].o+u[e].o;
		find(s,e);
		k1=ans;
		ans=u[s].o+u[e].o;
		find1(s,e);
		k2=ans;	
		cout<<min(k1,k2)<<endl;
	}
	return 0;
}
