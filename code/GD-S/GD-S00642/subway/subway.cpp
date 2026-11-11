#include<bits/stdc++.h>
using namespace std;
struct p{
	int gth=0;
	int bth[205];//iot, tt
}station[1100];
bool tr[205][1100];
int tidx,notr,nos,md,noq;
int que(int s,int e){
	int res=1e9;
	queue<pair<int,int>> pro;//loc,tt
	bool vis[1100];
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	for(int t=1;t<=notr;t++){
		if(station[s].bth[t]==0){
			continue;
		}
		if(tr[t][e]==1){
			res=min(res,station[e].bth[t]+station[s].bth[t]);
		}else{
			for(int i=1;i<=nos;i++){
				if(vis[i]==0&&tr[t][i]==1){
					pro.push({i,station[s].bth[t]+station[i].bth[t]});
				}
			}
		}
	}
	while(!pro.empty()){
		pair<int,int> f;
		f=pro.front();
		pro.pop();
		vis[f.first]=1;
		for(int t=1;t<=notr;t++){
			if(station[f.first].bth[t]==0){
				continue;
			}
			if(tr[t][e]==1){
				res=min(res,station[e].bth[t]+f.second+station[f.first].bth[t]);
			}else{
				for(int i=1;i<=nos;i++){
					if(vis[i]==0&&tr[t][i]==1){
						pro.push({i,f.second+station[f.first].bth[t]+station[i].bth[t]});
					}
				}
			}
		}
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>tidx>>notr>>nos>>md>>noq;
	for(int i=1;i<=nos;i++){
		cin>>station[i].gth;
		for(int j=0;j<=204;j++){
			station[i].bth[j]=0;
		}
	}
	for(int i=1;i<=notr;i++){
		int d=0;
		cin>>d;
		for(int j=1;j<=d;j++){
			int s,t;
			cin>>s>>t;
			station[s].bth[i]=t;
			tr[i][s]=1;
		}
	}
	for(int t=1;t<=noq;t++){
		int s,e;
		cin>>s>>e;
		cout<<que(s,e)+station[s].gth+station[e].gth<<endl;
	}
}
