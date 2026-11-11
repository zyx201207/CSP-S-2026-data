#include<bits/stdc++.h>
using namespace std;

const long long inf=4e18;

int c,n,m,d,q;//n条线路，m个站 
int w[500005];

int sm;
int k[505];
long long sum;
long long ans;
vector<int> a[505];
vector<int> t[505];
vector<int> g[500005];
vector<int> p[500005];

int ij;
int vis[505];
struct h{
	int x,y,z,e;
}o[5000006];
int fe[505];
long long s[505][505];
//o[5000006] -> 500*500*2

struct H{
	int tu;
	long long tsum;
};
priority_queue<H> pq;
bool operator <(H t1,H t2){
	return t1.tsum>t2.tsum;
}

void ycl(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			s[i][j]=inf;
		}
	}
	return;
}

void add(int sx,int sy,int sz){
	ij++;
	o[ij].x=sx;
	o[ij].y=sy;
	o[ij].z=sz;
	o[ij].e=fe[o[ij].x];
	fe[o[ij].x]=ij;
	return;
}

void dij(int px){
	s[px][px]=0;
	pq.push({px,0});
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!pq.empty()){
		H u=pq.top();
		pq.pop();
		if(vis[u.tu]==1)continue;
		else vis[u.tu]=1;
		
		for(int j=fe[u.tu];j;j=o[j].e){
			int v=o[j].y;
			if(s[px][u.tu]+o[j].z<=s[px][v]){
				s[px][v]=s[px][u.tu]+o[j].z;
				pq.push({v,s[px][v]});
			} 
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i].push_back(0);
		p[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int A,T;
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			g[A].push_back(i);
			p[A].push_back(j);
		}
	}
	
	ycl();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int siz=g[a[i][j]].size()-1;
			for(int op=1;op<=siz;op++){
				int ip=a[i][j];
				int id=g[ip][op];
				if(i==id)continue;
				else{
					sm=t[i][j]+t[id][p[ip][op]];
					s[i][id]=min(s[i][id],(long long)sm);
					s[id][i]=min(s[id][i],(long long)sm);
				}
			}
		}
	}//O(k_sum*d) -> 5e5*20=1e7
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]!=inf&&i!=j){
				add(i,j,s[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}//O(n^2long(n^2)) -> 2.5e5*20=5e6
	
	while(q--){
		int px,py;
		cin>>px>>py;
		int siz1=g[px].size()-1;
		int siz2=g[py].size()-1;
		
		ans=inf;
		for(int i=1;i<=siz1;i++){
			for(int j=1;j<=siz2;j++){
				sum=t[g[px][i]][p[px][i]]+t[g[py][j]][p[py][j]];
				ans=min(ans,sum+s[g[px][i]][g[py][j]]+w[px]+w[py]);
			}
		}
		cout<<ans<<"\n";
	}//O(q*d^2) -> 1e5*20*20=4e7
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
