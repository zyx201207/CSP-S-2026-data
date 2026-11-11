#include<bits/stdc++.h>
using namespace std;
int w[100005],a[10005][10005],t[10005][10005];
int tp2[10005][10005];
int c,n,m,d,q;
struct node{
	int of,Sub;
};
vector<node> g[10005]; 
bool vis[100005];
int Answer_Q(int s,int e,int St,int All_time,int Now){
	//cout<<"Subway "<<St<<" Time "<<All_time<<" Station "<<Now<<endl;
	if(Now==e){
		//cout<<"End\n";
		return All_time;
	}
	vis[Now]=1;
	int The_min=100005;
	for(node x:g[Now]){
		if(!vis[x.of]){
		//cout<<"Use Station "<<Now<<" 's subway "<<x.Sub<<" go to Station "<<x.of<<endl;
			if(St!=x.Sub){
				All_time+=t[x.Sub][Now];
				All_time+=t[x.Sub][x.of];
				The_min=min(Answer_Q(s,e,x.Sub,All_time,x.of),The_min);
				All_time-=t[x.Sub][Now];
				All_time-=t[x.Sub][x.of];
			}
			else{
				All_time+=t[x.Sub][x.of];
				The_min=min(Answer_Q(s,e,x.Sub,All_time,x.of),The_min);
				All_time-=t[x.Sub][x.of];
			}
		}
	}
	vis[Now]=0;
	return The_min;
}
int Dijkstra(int st,int Ret){
	int dist[10005]={0};
	dist[st]=0;
	memset(vis,0x3f,sizeof vis);
	for(int i=1;i<m;i++){
		int t=-1;
		for(int j=1;j<=m;j++){
			if(!vis[j]&&(t==-1||dist[j]<dist[t])) t=j;
		}
		vis[t]=1;
		for(int j=1;j<=n;j++){
			dist[j]=min(dist[j],dist[t]+tp2[t][j]);
		}
	}
	return dist[Ret];
}
int Answer2(int s,int e){
	return Dijkstra(s,e);
}
int main(){
	memset(tp2,0x3f,sizeof tp2);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){//Subway
		int ok;
		scanf("%d",&ok);
		for(int j=1;j<=ok;j++){//Station
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][a[i][j]]);
			t[a[i][j]][i]=t[i][a[i][j]];
			if(j==2) tp2[a[i][1]][a[i][2]]=t[i][a[i][1]]+t[i][a[i][2]];
			if(j==2) tp2[a[i][2]][a[i][1]]=t[i][a[i][1]]+t[i][a[i][2]];
			if(j>1){
				for(int k=1;k<j;k++){
					g[a[i][k]].push_back({a[i][j],i});
					g[a[i][j]].push_back({a[i][k],i});
				}
			}
		}
	}
	if(c>=9&&c<=11){
		if(0)
		while(q--){
			int oa,ob;
			scanf("%d%d",&oa,&ob);
			printf("%d\n",Answer2(oa,ob)+w[oa]+w[ob]);
		}
	}
	for(int i=1;i<=n;i++){
		//for(int j=1;j<=m;j++) cout<<t[i][j]<<" ";
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		//cout<<"From station "<<i<<" can arrive";
		for(int j=0;j<g[i].size();j++){
			//cout<<g[i][j].of<<" ";
		}
		//cout<<endl;
	} 
	while(q--){
		int oa,ob;
		scanf("%d%d",&oa,&ob);
		printf("%d\n",Answer_Q(oa,ob,0,0,oa)+w[oa]+w[ob]);
		memset(vis,0,sizeof vis);
	}
	return 0;
}
