#include<bits/stdc++.h>
using namespace std;

const int N=500,M=5e5,Q=1e5;
const int inf=2e9+7;
const long long INF=1e18;

int tid,n,m,d,q;
int w[M+5];
int ln[N+5];
vector<int> va[N+5],vt[N+5];
int A,T;
int qx[Q+5],qy[Q+5];
long long ans[Q+5];

vector<int> pi[M+5],pt[M+5];
int e[N+5][N+5];

void work1(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			e[i][j]=inf;
		}
		e[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<ln[i];++j){
			int x=va[i][j];
			pi[x].push_back(i);
			pt[x].push_back(vt[i][j]);
		}
	}
	for(int p=1;p<=m;++p){
		for(int i=0;i<pi[p].size();++i){
			for(int j=0;j<pi[p].size();++j){
				e[pi[p][i]][pi[p][j]]=min(e[pi[p][i]][pi[p][j]],pt[p][i]+pt[p][j]);
			}
		}
	}
	return;
}

long long dis[N+5][N+5];
int fg[N+5];

void dij(int st){
	dis[st][0]=INF;
	for(int i=1;i<=n;++i){
		dis[st][i]=INF;
		fg[i]=0;
	}
	dis[st][st]=0;
	for(int i=1;i<=n;++i){
		int mp=0;
		for(int p=1;p<=n;++p){
			if(fg[p]==0 && dis[st][p]<dis[st][mp]){
				mp=p;
			}
		}
		fg[mp]=1;
		for(int p=1;p<=n;++p){
			if(e[mp][p]!=inf){
				dis[st][p]=min(dis[st][p],dis[st][mp]+e[mp][p]);
			}
		}
	}
	return;
}

void work2(){
	for(int i=1;i<=n;++i){
		dij(i);
	}
	return;
}

void work3(){
	for(int i=1;i<=q;++i){
		int x=qx[i],y=qy[i];
		long long rt=INF;
		for(int xi=0;xi<pi[x].size();++xi){
			for(int yi=0;yi<pi[y].size();++yi){
				rt=min(rt,dis[pi[x][xi]][pi[y][yi]]+pt[x][xi]+pt[y][yi]);
			}
		}
		ans[i]=rt+w[x]+w[y];
	}
	return;
}

void solve(){
	work1();
	work2();
	work3();
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tid>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>ln[i];
		for(int j=0;j<ln[i];++j){
			cin>>A>>T;
			va[i].push_back(A);
			vt[i].push_back(T);
		}
	}
	for(int i=1;i<=q;++i){
		cin>>qx[i]>>qy[i];
	}
	solve();
	for(int i=1;i<=q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}//answer 100pts
