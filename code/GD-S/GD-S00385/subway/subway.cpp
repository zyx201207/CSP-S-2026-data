#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
struct passby{
	int stn;
	int t2c;
};
long long c,m,n,d,q,ans;
int pl[100005][2];
vector<passby>rail[505];
int walkt[500005];
bool vis[500005];
vector<int>station[500005];

int bfs(int st,int en){
	memset(vis,0,sizeof(vis));
	queue<int>iqs;
	long ust[m],cgt;
	
	//cout<<ust[st]<<"\n";
	for(int i=0;i<m;i++){
		ust[i]=1e9;
	}
	ust[st]=0;
	//cout<<"inited..\n";
	for(int i:station[st]){
		for(passby t:rail[i]){
		if(t.stn==st){
			cgt=t.t2c;
			break;
		}
		}
		for(passby t:rail[i]){
			if(t.stn!=st){
				iqs.push(t.stn);
				ust[t.stn]=min(ust[t.stn],ust[st]+t.t2c+cgt);
			}
		}
	}
	
	while(!iqs.empty()){
		int p=iqs.front();
		iqs.pop();
		for(int i:station[p]){
			for(passby t:rail[i]){
			if(t.stn==p){
				cgt=t.t2c;
				break;
			}
			}
			for(passby t:rail[i]){
				if(t.stn!=p){
					if(!vis[t.stn]){
					iqs.push(t.stn);
					vis[t.stn]=1;	
					}
					
					ust[t.stn]=min(ust[t.stn],ust[p]+t.t2c+cgt);
				}
			}
		}
		
	}
//	for(int i=0;i<m;i++){
//		if(i==st)
//		cout<<"#";
//		cout<<ust[i]<<' ';
//	}
	return ust[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>walkt[i];
	}
	for(int i=0;i<n;i++){
		int k0;
		cin>>k0;
		for(int j=0;j<k0;j++){
			int ak,tk;
			cin>>ak>>tk;
			rail[i].push_back({ak-1,tk});
			station[ak-1].push_back(i);
		}
	}
	for(int i=0;i<q;i++){
		cin>>pl[i][0]>>pl[i][1];
		pl[i][0]--;
		pl[i][1]--;
	}
	

if(c!=0){
	for(int i=0;i<q;i++){
		ans=1e14;
		//memset(vis,0,sizeof(vis));
		cout<<(int)bfs(pl[i][0],pl[i][1])+walkt[pl[i][0]]+walkt[pl[i][1]]<<"\n";
	}
}else{
	for(int i=0;i<q;i++){
		ans=1e14;
		//memset(vis,0,sizeof(vis));
		cout<<(int)bfs(pl[i][0],pl[i][1])+walkt[pl[i][0]]+walkt[pl[i][1]]<<"\n";
	}
	
}
	return 0;
}
