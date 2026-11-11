#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,Aaa,a;
ll b,x[200010],wow;
vector <int> hd[200010];
ll dis[200010],vis[200010];
struct h{
	int n;
	ll w;
};
bool operator<(h q,h r){
	return q.w>r.w;
}
priority_queue <h> p0;
void djk(int x){
	for(int i=1;i<=a;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis[x]=0;
	vis[x]=100;
	while(!p0.empty()) p0.pop();
	p0.push({x,0});
	while(!p0.empty()){
		h p=p0.top();
		p0.pop();
		if(p.w>dis[p.n]) continue;
		for(int i=0;i<hd[p.n].size();i++){
			int v=hd[p.n][i];
			if(p.w+1<dis[v]){
				dis[v]=p.w+1;
				vis[v]=0;
			}
			if(p.w+1==dis[v]){
				vis[v]++;
				p0.push({v,p.w+1});
			}
		}
	}
	for(int i=1;i<=a;i++){
	//	cout<<vis[i]<<" ";
		if(i!=x&&vis[i]==2) wow++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>Aaa;
	for(int ii=1;ii<=Aaa;ii++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>x[i];
			hd[i].clear();
		}
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if(x[j]-x[i]<=b){
					hd[i].push_back(j);
					hd[j].push_back(i);
				}
			}
		}
		wow=0;
		for(int i=1;i<=a;i++){
			djk(i);
		}
		cout<<wow/2<<"\n";
	}
	return 0;
}
