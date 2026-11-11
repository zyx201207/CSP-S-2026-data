#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
struct Node{
	int x,y;
};
const int N=5e5+5,M=505;
int n,m,q;
vector<Node>v[N];
vector<int>lu[N];
int h[N][505];
int w[N],u[N],a[N];
map<int,map<int,long long> > d;
void solve(){
	int st,en;
	scanf("%d %d",&st,&en);
	for(int i=1;i<=m;i++){
		for(auto j:lu[i]){
			d[i][j]=9e17;
		}
	}
	for(auto i:lu[st]) d[st][i]=0;
	vector<Node>q;
	q.push_back({st,0});
	while(q.size()){
		int k=0;
		for(int i=0;i<q.size();i++){
			if(d[q[i].x][q[i].y]<d[q[k].x][q[k].y]) k=i;
		} 
		Node f=q[k];
		q.erase(q.begin()+k);
		for(auto i:v[f.x]){
			int c;
			if(f.y==0) c=h[f.x][i.y];
			else if(i.y==f.y) c=0;
			else c=h[f.x][f.y]+h[f.x][i.y];
			c+=d[f.x][f.y];
			if(d[i.x][i.y]>c){
				d[i.x][i.y]=c;
				q.push_back({i.x,i.y});
			}
		}
	}
	long long ans=9e17;
	for(auto i:lu[en]){
		ans=min(ans,d[en][i]+h[en][i]);
	}
	printf("%lld\n",ans+w[st]+w[en]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Q;
	scanf("%*d %d %d %*d %d",&n,&m,&Q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,l=0;
		scanf("%d",&k);
		for(int j=1;j<=2*k;j++){
			int t;
			scanf("%d",&t);
			if(j%2==0){
				h[l][i]=t;
			}else{
				lu[t].push_back(i);
				if(l==0){
					l=t;
					continue;
				}
				v[t].push_back({l,i});
				v[l].push_back({t,i});
				l=t; 
			}
		}
	} 
	while(Q--){
		solve();
	}
	return 0;
}

