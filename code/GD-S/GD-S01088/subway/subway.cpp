#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
using std::cin;using std::cout;
using std::string;using std::vector;using std::map;
const int N=5e5+10,M=505;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
namespace zyh{
	map<int,int> xm[M];//线路->车站 
//	vector<int> a[M];
	vector<int> pm[N];//车站->线路 
	ll w[N];
	int c,n,m,d,Q;
	int mrx[M][M];
	struct node{
		int to,nxt;
		ll val;
	}edge[2*M*M];
	int head[M];
	int cnt;
	
	void add(int u,int v,int w){
//		cout<<"add: "<<u<<' '<<v<<' '<<w<<'\n';
		edge[++cnt]={v,head[u],w};
		head[u]=cnt;
	}
	ll dis[M][M];
	struct ccf{
		int pos;
		ll val;
		friend bool operator<(ccf x,ccf y){return x.val>y.val;}
	};
	std::priority_queue<ccf> q;
	void dij(int x){
		for(int i=1;i<=n;i++) dis[x][i]=INF;
		//dis[x][x]=0;
		q.push({x,0});
		while(!q.empty()){
			ccf now=q.top();
			q.pop();
			if(dis[x][now.pos]<=now.val) continue;
			dis[x][now.pos]=now.val;
			for(int i=head[now.pos];i!=-1;i=edge[i].nxt){
				if(dis[x][edge[i].to]>now.val+edge[i].val){
					q.push({edge[i].to,now.val+edge[i].val});
				}
			}
		}
	}
	signed lqr(){
		memset(head,-1,sizeof(head));
		cin>>c>>n>>m>>d>>Q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int kk;
			cin>>kk;
			while(kk--){
				int aa,tt;
				cin>>aa>>tt;
				xm[i][aa]=tt;
				pm[aa].push_back(i);
			}
		}
		//cout<<"check line:\n";
		for(int i=1;i<=m;i++){
			int tlen=pm[i].size();
			for(int j=0;j<tlen;j++){
				//cout<<pm[i][j]<<' ';
				for(int k=1;k<tlen;k++){
					int jj=pm[i][j],kk=pm[i][k];
					int tw=xm[jj][i]+xm[kk][i];
					if(!mrx[jj][kk]) mrx[jj][kk]=tw;
					else mrx[jj][jj]=std::min(mrx[jj][kk],tw);
					if(!mrx[kk][jj]) mrx[kk][jj]=tw;
					else mrx[kk][jj]=std::min(mrx[jj][kk],tw);
				}
			}
			//cout<<'\n';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||!mrx[i][j]) continue;
				add(i,j,mrx[i][j]);
				add(j,i,mrx[j][i]);
			}
		}
//		return 0;
//		cout<<'\n';
		for(int i=1;i<=n;i++) dij(i);
		while(Q--){
			int xx,yy;
			cin>>xx>>yy;
			ll ans=INF;
//			cout<<"find:\n";
			for(auto i:pm[xx]){
				for(auto j:pm[yy]){
//					cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<xm[i][xx]<<' '<<xm[j][yy]<<'\n';
					ans=std::min(ans,dis[i][j]+xm[i][xx]+xm[j][yy]);
				}
			}
			cout<<ans+w[xx]+w[yy]<<'\n';
		}
//		cout<<"check:\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dis[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		return 0;
	}
}
void IO_set(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
signed main(){
	IO_set("subway");
	return zyh::lqr();
}
//pass all samples 16:27
//fix memory issues 16:35
