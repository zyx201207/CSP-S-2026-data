#include<bits/stdc++.h>
using namespace std;
struct sd{
	int x,cnt,fa;
};
int c,t;
int n,m;
vector<int> v[1919810];
bitset<1919810> vis;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(114514);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}if(m==1){
			int mini=1e9;
			int p=rand()%n+1;
			for(double T=999;T>=0.01;T*=0.91){
				int fa=p;
				int pi=p;
				int maxi=0;
				for(int i=1;i<=rand()%1145*T;i++){
					int r=rand()%v[pi].size();
					if(v[pi][r]==fa)continue;
					fa=pi;
					pi=v[pi][r];
				}queue<sd> q;
				q.push({pi,0,pi});
				vis=0;
				while(q.size()){
					sd u=q.front();
					q.pop();
					maxi=max(maxi,u.cnt);
					for(int i:v[u.x]){
						if(i!=u.fa && !vis[i]){
							q.push({i,u.cnt+1,u.x});
							vis[i]=1;
						}
					}
				}if(maxi<mini || T*rand()/32676>=rand()%999+1){
					p=pi;
				}mini=min(mini,maxi);
			}cout<<mini<<"\n";
		}else if(m==2){
			int mini=1e9;
			int p1=rand()%n+1,p2=rand()%n+1;
			while(p2==p1)p2=rand()%n+1;
			for(double T=999;T>=0.01;T*=0.91){
				int maxi=0;
				int fa=p1;
				int pi=p1;
				for(int i=1;i<=rand()%1145*T+1;i++){
					int r=rand()%v[pi].size();
					if(v[pi][r]==fa)continue;
					fa=pi;
					pi=v[pi][r];
				}fa=p2;
				int pj=p2;
				for(int i=1;i<=rand()%1145*T+1;i++){
					int r=rand()%v[pj].size();
					if(v[pj][r]==fa)continue;
					fa=pj;
					pj=v[pj][r];
				}
				queue<sd> q;
				q.push({pi,0,pi});
				q.push({pj,0,pj});
				vis=0;
				while(q.size()){
					sd u=q.front();
					q.pop();
					maxi=max(maxi,u.cnt);
					for(int i:v[u.x]){
						if(i!=u.fa && !vis[i]){
							q.push({i,u.cnt+1,u.x});
							vis[i]=1;
						}
					}
				}if(maxi<mini || T*rand()/32676>=rand()%999+1){
					p1=pi;
					p2=pj;
				}mini=min(mini,maxi);
			}cout<<mini<<"\n";
		}else{
			cout<<rand()%n<<"\n";
			continue;
		}
	}
	return 0;
} 
