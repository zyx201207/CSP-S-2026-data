#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
const int M=2e3+10,N=5e2+10;
int c,n,m,d,q,w[M],k[N],dits[M][N];
vector<int> a[N],t[N];
int bj[M],sf[M];
struct U1{
	int x,No;
};

struct U2{
	int x,No;
};
vector<U1> v[M],belong[M];
void bfs(int s,int f){
	queue<U2> q;
	q.push({s,sf[s]});
	dits[s][sf[s]]=0;
	while(!q.empty()){
		U2 a=q.front();
		q.pop();
		cout<<a.x<<" "<<dits[a.x][a.No]<<"\n"; 
		for(U1 nx:v[a.x]){
			if(nx.No!=a.No) dits[nx.x][nx.No]=min(dits[nx.x][nx.No],dits[a.x][a.No]+t[nx.No][nx.x]+t[a.No][a.x]);
			else dits[nx.x][nx.No]=min(dits[nx.x][nx.No],dits[a.x][a.No]);
			q.push({nx.x,nx.No});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int bf=-1;
		for(int j=1;j<=k[i];j++){
			int aij,tij;
			cin>>aij>>tij;
			a[i].push_back(aij);
			t[i].push_back(tij);
			if(j!=1) v[bf].push_back({aij,i}),v[aij].push_back({bf,i});
			belong[aij].push_back({i,tij});
		}
	}
	memset(bj,0x3f,sizeof bj);
	for(int i=1;i<=m;i++){
		for(int j=0;j<belong[i].size();j++){
			if(bj[j]<belong[i][j].No){
				bj[j]=belong[i][j].No;
				sf[j]=belong[i][j].x;
			}
			for(int k=j+1;k<belong[i].size();k++){
				v[j].push_back({k,belong[i][k].No});
				v[k].push_back({j,belong[i][j].No});
			}
		}
	}
	for(int i=1;i<=q;i++){
		memset(dits,0x3f,sizeof dits);
		int xr,yr;
		cin>>xr>>yr;
		bfs(xr,yr);
		cout<<dits[yr]<<"\n";
	}
	return 0;
}
