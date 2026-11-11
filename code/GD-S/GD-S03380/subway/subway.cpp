#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,N,M,D,Q;
struct edge{
	int point,val;
	const bool operator<(const edge& idk)const{
		return idk.val<val;
	}
};
struct node{
	int from,to,price;
};
int jzval[505];//进站时间
int zcval[505];//坐车时间 
//int dis[505],n/*点*/,m/*边*/,st;
//bool vis[505];
vector<edge>pic[505];
priority_queue<edge>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>n>>m>>st;
	cin>>c>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>jzval[i];
	}
//	memset(dis,0x3f,sizeof(dis));
//	dis[st]=0;
	for(int i=1;i<=N;i++){
		int st_num;
		cin>>st_num;
		for(int j=1;j<=st_num;j++){
			int id,tim;
			cin>>id>>tim;
			if(id==i)zcval[i]=tim;
			else{
				int u=i,v=id,w=tim;
				pic[u].push_back(edge{v,w});
//				pic[v].push_back(edge{u,w});
			}
		}
	} 
//	for(int i=1;i<=m;i++){
//		int u/*起点*/,v/*终点*/,w/*边权*/;
//		cin>>u>>v>>w;
//		pic[u].push_back(edge{v,w});
//		pic[v].push_back(edge{u,w});
//	}
	for(int idk=1;idk<=Q;idk++){
		int dis[505],n/*点*/,m/*边*/,st,en;
		bool vis[505];
//		int st,en;
		cin>>st>>en;
		memset(dis,0x3f,sizeof(dis));
//		memset(vis,0,sizeof(vis));
//		memset(pic,0,sizeof(pic));
		dis[st]=jzval[st]+zcval[st];
		q.push(edge{st,jzval[st]+zcval[st]});
		while(!q.empty()){
			edge nowinfo=q.top();
			q.pop();
			int nowpoint=nowinfo.point,nowval=nowinfo.val;
			if(vis[nowpoint])continue;
			else{
				vis[nowpoint]=1;
				for(edge tmp:pic[nowpoint]){
					int targetpoint=tmp.point,targetval=tmp.val;
					if(dis[targetpoint]>dis[nowpoint]+targetval){
						dis[targetpoint]=dis[nowpoint]+targetval+zcval[nowpoint]+zcval[targetpoint];
						q.push(edge{targetpoint,dis[targetpoint]});
					}
				}
			}
		}
		cout<<dis[en]+jzval[en]-zcval[en]<<endl;
	}
	//鸀爨鵩 
//	for(int i=1;i<=M;i++){
//		for(edge tmp:pic[i]){
//			cout<<i<<" "<<tmp.point<<" "<<tmp.val<<endl;
//		}
//	}
	return 0;
}
