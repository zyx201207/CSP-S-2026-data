#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 505;
const int MAXM = 500005;


ll read(){
	ll res_;
	bool f_=false;
	char ch_;
	ch_=getchar();
	while(ch_<'0'||ch_>'9'){
		if(ch_=='-')f_=true;
		ch_=getchar();
	}
	while(ch_>='0'&&ch_<='9'){
		res_*=10;
		res_+=ch_-'0';
		ch_=getchar();
	}
	return res_*(f_?-1:1);
}
int readInt(){
	int res_;
	bool f_=false;
	char ch_;
	ch_=getchar();
	while(ch_<'0'||ch_>'9'){
		if(ch_=='-')f_=true;
		ch_=getchar();
	}
	while(ch_>='0'&&ch_<='9'){
		res_*=10;
		res_+=ch_-'0';
		ch_=getchar();
	}
	return res_*(f_?-1:1);
}

struct E{
	int roadn;
	int rs;
	ll useT;
}tmp1;
struct Node{
	unordered_map<int,E>t;//路序号以及用时 
	long long w;//进出用时 
};
Node G[MAXM];
vector<int> ways[MAXN];

struct Edge{
	int to;
	long long w;
}tmp;
vector<Edge> G1[MAXN];
bool vis[MAXM];

int n,m,c,d,q;

long long D_d[MAXM];

ll Dijkstra(int u,int target){
	memset(D_d,0x3f,sizeof(D_d));
	fill(vis,vis+MAXM-3,false);
	vis[u]=true;
	D_d[u]=0;
	int nowu = u;
	while(true){
		bool flag_=true;
		vis[nowu]=true;
		int minn=0;
		long long minw=2147483647;
		for(Edge i:G1[nowu]){
			int v = i.to;
			ll w = i.w;
			if(vis[v]){
				continue;
			}
			flag_=false;
			if(D_d[v]>D_d[nowu]+w){
				D_d[v]=D_d[nowu]+w;
			}
			if(D_d[v]<minw){
				minw=D_d[v];
				minn=v;
			}
		}
		if(flag_||minn==0)break;
		nowu=minn;
	}
	for(int s=1;s<=m;s++){
		if(vis[s])continue;
		int nowu = s;
		while(true){
			bool flag_=true;
			vis[nowu]=true;
			int minn=0;
			long long minw=2147483647;
			for(Edge i:G1[nowu]){
				int v = i.to;
				ll w = i.w;
				if(vis[v]){
					continue;
				}
				flag_=false;
				if(D_d[v]>D_d[nowu]+w){
					D_d[v]=D_d[nowu]+w;
				}
				if(D_d[v]<minw){
					minw=D_d[v];
					minn=v;
				}
			}
			if(flag_||minn==0)break;
			nowu=minn;
		}
	}	
	return D_d[target];
}

bool viss[MAXM];
ll search_(int u,int v,int r){
	if(u==v)return G[v].t[r].useT;
	viss[u]=true;
	ll res= 0xfffffff;
	for(auto i_:G[u].t){
		E i=i_.second;
		ll nowres = 0;
		int nowr = i.roadn;
		int nowrp = i.rs;
		if(r!=nowr){
			nowres+=i.useT;
			nowres+=G[u].t[r].useT;
		}
		if(ways[nowr].size()>nowrp){
			if(!viss[ways[nowr][nowrp+1]]){
				nowres=search_(ways[nowr][nowrp+1],v,nowr);
				res=min(res,nowres);
			}
		}
	}
	viss[u]=false;
	return res;
}

ll solve(int qa,int qb){
	ll ans=0xfffffff;
	for(auto i_:G[qa].t){
		E i=i_.second;
		ll nowans=0;
		fill(viss,viss+MAXM-3,false);
		viss[qa]=true;
		int nowr = i.roadn;
		int nowrp = i.rs;
		nowans+=i.useT;
		if(ways[nowr].size()>nowrp){
			nowans+=search_(ways[nowr][nowrp+1],qb,nowr);
			ans=min(ans,nowans);
		}
	}
	ans+=G[qa].w+G[qb].w;
	return ans;
}




signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>G[i].w;
	}
	for(int i=1;i<=n;i++){
		int kkk,aaa;
		ll ttt;
		cin>>kkk;
		if(kkk==1){
			cin>>aaa>>ttt;
			continue;
		}
		if(kkk==2){
			int aaa2;
			ll ttt2;
			cin>>aaa>>ttt>>aaa2>>ttt2;
			tmp.to=aaa2;
			tmp.w=ttt+ttt2;
			G1[aaa].push_back(tmp);
			continue;
		}
		for(int j=1;j<=kkk;j++){
			cin>>aaa;
			cin>>ttt;
			ways[i].push_back(aaa);
			tmp1.roadn=i;
			tmp1.rs=j-1;
			tmp1.useT=ttt;
			G[aaa].t[i]=tmp1;
		}
	}
	if(c>=7&&c<=11){
		while(q--){
			int qa,qb;
			cout<<Dijkstra(qa,qb)<<"\n";
		}
		return 0;
	}
	while(q--){
		int qa,qb;
		cin>>qa>>qb;
		cout<<solve(qa,qb)<<endl;
	}
	
	
	
	return 0;
}
