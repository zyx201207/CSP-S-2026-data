#include<bits/stdc++.h>
using namespace std;
int n,m,t[501][20001],vis[20001],vis2[501],res,c,k,w[20001],d,q,x[100001],y[100001];
vector<int> p[20001],f[20001];
void dfs(int pos,int time,int finish,bool type){
	if(type){
		vis[pos]=1;
		if(pos==finish){
			vis[pos]=0;
		res=min(res,time);
		//cout<<pos<<" "<<finish<<" "<<time<<endl;
		return;
	}
	for(auto e:p[pos]){
		//cout<<"change!"<<t[pos][e]<<endl;
		if(vis2[e]==0){
		vis2[e]=1;
		dfs(e,time+t[e][pos],finish,!type);
		vis2[e]=0;}
	}
	}
	else{
		for(auto e:f[pos]){
		if(vis[e]==0){
			//cout<<"change2!"<<t[pos][e]<<endl;
			vis[e]=1;
			dfs(e,time+t[pos][e],finish,!type);
			vis[e]=0;
		}
	}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int tmp;
		for(int j=1;j<=k;j++){
			scanf("%d",&tmp);
			p[tmp].push_back(i);
			f[i].push_back(tmp);
			scanf("%d",&t[i][tmp]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
	}
	for(int i=1;i<=q;i++){
		int answer=0;
		answer+=w[x[i]];
		answer+=w[y[i]];
		vis[x[i]]=1;
		res=2147363847;
		dfs(x[i],0,y[i],1);
		printf("%d\n",res+answer);
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
	}
	return 0;
} 
