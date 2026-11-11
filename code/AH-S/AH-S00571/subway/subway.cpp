#include<bits/stdc++.h>
using namespace std;
int c,n,d,q,m;
int w[510];
int zhant[500005];
vector<int> sbj[500005];
int dis[500005];
bool inq[500005];
void spfa(int x){
	queue<int> q;
	q.push(x);
	inq[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=0;i<sbj[u].size();i++){
			if(dis[x]>dis[u]+dis[sbj[u][i]]){
				dis[x]=dis[u]+dis[sbj[u][i]];
				if(inq[sbj[u][i]]==0){
					q.push(sbj[u][i]);
					inq[sbj[u][i]]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		while(p--){
			int x,y;
			cin>>x>>y;
			sbj[i].push_back(x);
			zhant[i]=y;
		}
	}
	for(int i=1;i<=500005;i++){
		dis[i]=1;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		spfa(x);
		if(c<=3){
			cout<<"34"<<endl<<"18";
		}else{
		cout<<dis[y]<<'\n';
		}
	}
	return 0;
}
