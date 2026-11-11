#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20005;
ll ans=0;
int c,n,m,d,q;
int sta[N];//出站时间 
int line[505][N];//line[i][j]第i条线路的j站点出站进站时间 
vector<int>li[505];//第i条线路可以通往哪几个站点
vector<int>stl[N];//第i个站点可以转到哪条线路
bool isinz[505][N];//第i条线路有没有j这个站点 
int k[505];
int search(int lin,int x,int ed,int cost,bool vis[]){
	if(x==ed){
		cost+=line[lin][x];
		return cost;
	}
	for(int i=0;i<stl[x].size();i++){
		if(stl[x].size()==1)break;
		if(stl[x][i]==lin)continue;
		int cl=stl[x][i];
		if(isinz[cl][ed]==1){
			cost+=line[lin][x];
			cost+=line[cl][x];
			search(cl,ed,ed,cost,vis);
		}
		else{
			for(int j=0;j<li[cl].size();j++){
				if(vis[li[cl][j]])continue;
				vis[li[lin][j]]=1;
				cost+=line[lin][x];
				cost+=line[cl][x];
				search(cl,x,ed,cost,vis);
			}
		}
		
	}
	for(int j=0;j<li[lin].size();j++){
			if(isinz[lin][ed]==1){
				search(lin,ed,ed,cost,vis);
			}
			else{
				if(vis[li[lin][j]])continue;
				vis[li[lin][j]]=1;
				search(lin,li[lin][j],ed,cost,vis);	
			}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>sta[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int st,ti;
			cin>>st>>ti;
			li[i].push_back(st);
			stl[st].push_back(i);
			isinz[i][st]=1;
			line[i][st]=ti;
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		int ans=sta[st]+sta[ed];
		int cnt=INT_MAX;
		for(int i=0;i<stl[st].size();i++){
			int cost=0;
			bool vis[N];
			cost+=line[stl[st][i]][st];
			cost+=search(stl[st][i],st,ed,0,vis);
			cnt=min(cnt,cost);
		}
		ans+=cnt;
		cout<<ans<<endl;
	}
	return 0;
}

