#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[20005];
struct node1{
	int x,y;
}b[505][20005];
struct node{
	int x;
	ll y;
	int z;
};
struct node2{
	int x,y;
};
ll dis[20055];
int tingtime[505][20005];
vector<int> adj[20005];
priority_queue<node> q;
bool f[20005];
bool operator < (node t1,node t2){
	return t1.y>t2.y;
}
int T,lincnt,n,maxguo,p;
vector<node2> v[20005];
ll dij(int lin,int st,int fina){
	q.push({st,a[st]+tingtime[lin][st],lin});
	f[st]=1;
	dis[st]+=tingtime[lin][st];
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int p1=t.x,p2,p3;
		for(int i=0;i<v[p1].size();i++){
			p3=v[p1][i].x;
			for(int j=0;j<adj[p3].size();j++){
				p2=adj[p3][j];
				bool flag=0;
				if(p2==t.z){
					if(p3==fina){
						if(!f[p3]&&dis[p1]+tingtime[t.z][p3]<dis[p3]){
							flag=1;
							dis[p3]=dis[p1]+tingtime[t.z][p3];
							q.push({p3,t.y,t.z});
						}
					}else if(!f[p3]&&dis[p1]<dis[p3]){
						flag=1;
						dis[p3]=dis[p1];
						q.push({p3,t.y,t.z});
					}
				}else{
					if(p3==fina){
						if(!f[p3]&&dis[p1]+tingtime[t.z][p1]+tingtime[p2][p1]+tingtime[p2][p3]<dis[p3]){
							dis[p3]=dis[p1]+tingtime[t.z][p1]+tingtime[p2][p1]+tingtime[p2][p3];
							flag=1;
							q.push({p3,dis[p3],p2});
						}
					}else if(!f[p3]&&dis[p1]+tingtime[t.z][p1]+tingtime[p2][p1]<dis[p3]){
						dis[p3]=dis[p1]+tingtime[t.z][p1]+tingtime[p2][p1];
						flag=1;
						q.push({p3,dis[p3],p2});
					}
				}
				if(flag) f[p3]=1;
			}
		}
	}
	return dis[fina]+a[fina];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T>>lincnt>>n>>maxguo>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ki;
	for(int i=1;i<=lincnt;i++){
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>b[i][j].x>>b[i][j].y;
			adj[b[i][j].x].push_back(i);
			tingtime[i][b[i][j].x]=b[i][j].y;
		}
		for(int j=1;j<ki;j++){
			v[b[i][j].x].push_back({b[i][j+1].x,i});
			v[b[i][j+1].x].push_back({b[i][j].x,i});
		}
	}
	int xi,yi;
	ll min1=1e18;
	for(int i=1;i<=p;i++){
		cin>>xi>>yi;
		min1=1e18;
		for(int j=0;j<adj[xi].size();j++){
			for(int j=1;j<=n;j++) dis[j]=1e18;
			dis[xi]=a[xi];
			min1=min(min1,dij(adj[xi][j],xi,yi));
			memset(f,0,sizeof f);
		}
		cout<<min1<<endl;
	}
	return 0;
}
