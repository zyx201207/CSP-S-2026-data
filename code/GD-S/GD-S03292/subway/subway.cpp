#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,que;
int w[500010];
int K[500010];
int a[500010];
int t[500010];
int T;
//int line[550][2010];
vector<int>li[500010];
int dis[1010][1010];
bool f=true;
//int t[550][500010];
vector<pair<int ,int > >e[500010];
vector<pair<int,int > >E[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>que;
	if(12<=c&&c<=19){
		f=false;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		K[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			T=t[j];
			if(f){
			for(int l=1;l<j;l++){
				e[a[j]].push_back({a[l],t[j]+t[l]});
				e[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
//			line[i][a[j]]=t[j];
			li[a[j]].push_back(i);
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<"---->";
//		for(auto man: e[i]){
//			cout<<man.first<<"/"<<man.second<<" ";
//		}
//		cout<<"\n";
//	}
if(f){
for(int i=1;i<=m;i++){
	priority_queue<pair<int,int > > q;
	q.push({0,i});
	dis[i][i]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		for(auto man : e[u]){
			int v=man.first;
			int w=man.second;
			if(dis[i][u]+w<dis[i][v]){
			dis[i][v]=dis[i][u]+w;
			q.push({dis[i][v],v});
				}
			}
		}
	}
	for(int i=1;i<=que;i++){
		int st,en;
		cin>>st>>en;
		cout<<dis[st][en]+w[st]+w[en]<<"\n"; 
	}
}
else{
	for(int i=1;i<=m;i++){
		for(int j : li[i]){
			for(int k : li[i]){
				if(j!=k){
//					cout<<i<<" "<<j<<"\n";
					E[j].push_back({k,2*T});
					E[k].push_back({j,2*T});
				}
			} 
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j : li[i]){
//			cout<<j<<" ";
//		} 
//		cout<<"\n";
//	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<"---¡· ";
//		for(auto j : E[i]){
//			cout<<j.first<<" ";
//		}
//		cout<<"\n";
//	}
	
	
	for(int i=1;i<=n;i++){
	priority_queue<pair<int,int> >q2;
	q2.push({0,i});
	dis[i][i]=0;
	while(q2.size()){
		int u=q2.top().second;
		q2.pop();
		for(auto man : E[u]){
			int v = man.first;
			int w = man.second;
			if(dis[i][u]+w<dis[i][v]){
				dis[i][v]=dis[i][u]+w;
				q2.push({dis[i][v],v});
			}
		}
	}
}
	for(int i=1;i<=que;i++){
//		cout<<"q ";
		int st,en;
		cin>>st>>en;
		int ans=1e9;
		for(int j : li[st]){
			for(int l : li[en]){
				if(j!=l)ans=min(ans,dis[j][l]+w[st]+w[en]+2*T);
				if(j==l){
					ans=min(ans,dis[j][l]+w[st]+w[en]);
				}
			}
		}
		cout<<ans<<"\n";
	}
}
	return 0;
} 
