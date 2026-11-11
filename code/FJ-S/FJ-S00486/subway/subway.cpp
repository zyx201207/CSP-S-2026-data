#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int ww[500005];
vector<pair<int,int>>e[500005];
int flag[500005][35];
int dis2[500005];
int cc[500005][35];
int dis[500005],dis_c[500005];
map<int,bool>mp;
void dij(int uu){
	memset(dis,0x3f,sizeof(dis));
	memset(dis2,0x3f,sizeof(dis2));
	dis[uu]=0;
	dis2[uu]=0;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
	q.push({0,{uu,-1}});
	while(!q.empty()){
		int u=q.top().second.first;
		int fl=q.top().second.second;
		q.pop();
		for(auto f:e[u]){
			int k=f.first,cnt=f.second;
			if(cnt==fl)continue;
			int dist=dis[u]+flag[u][cnt]+flag[u][fl];
			//if(fl==cnt)dist-=flag[u][cnt]+flag[u][fl];
			if(dist<dis[k]||(dis_c[k]!=cnt&&dist==dis[k])){
				dis[k]=dist;
				dis_c[k]=cnt;
				q.push({dist,{k,cnt}});
			}
			if(dist+flag[k][cnt]+ww[k]+ww[uu]<dis2[k]){
				dis2[k]=dist+flag[k][cnt]+ww[k]+ww[uu];	
			}
			//cout<<k<<" "<<u<<" "<<" "<<fl<<" "<<cnt<<" "<<dist<<" "<<dis[k]<<" "<<dis2[k]<<endl;
			//cout<<dis2[k]<<" "<<dist<<" "<<flag[k][cnt]<<" "<<ww[k]<<" "<<ww[uu]<<" "<<k<<" "<<cnt<<endl;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>ww[i];
	}	
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++){
			int x;
			cin>>cc[j][i]>>x;
			flag[cc[j][i]][i]=x;
		} 
		for(int j=1;j<=k;j++){
			for(int kk=1;kk<=k;kk++){
				
				e[cc[j][i]].push_back({cc[kk][i],i});
				e[cc[kk][i]].push_back({cc[j][i],i});
		}}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		dij(l);
		cout<<dis[r]<<endl;
		//for(int i=1;i<=n;i++)cout<<dis[i]<<" "<<dis2[i]<<endl;
	}
	
	
	return 0;
}
