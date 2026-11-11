#include<bits/stdc++.h>
#define ll long long
#define FR(a,b,c) for(int a=b;a<=c;++a)
#define RF(a,b,c) for(int a=b;a>=c;--a)
using namespace std;
const int N=3e5+7;
const int M=7000;
ll c,n,m,d,q,cr[N],tim[M][M],f[507];
struct node{
	ll op;
	ll nxto;
};
ll sta[N][507];
vector<node> u[N];
void dfs(ll x,ll now,ll nowop,ll spd){
	if(tim[x][now]==-1||tim[x][now]>(spd+sta[now][nowop])){
		tim[x][now]=spd+sta[now][nowop];
		tim[now][x]=spd+sta[now][nowop];
	}
	f[now]=1;
	for(ll l=0;l<u[now].size();++l){
		ll nxt=u[now][l].nxto;
		ll uop=u[now][l].op;
		if(f[nxt]==0){
			if(nowop!=uop){
				dfs(x,nxt,uop,spd+sta[now][nowop]+sta[now][uop]);
			}else{
				dfs(x,nxt,nowop,spd);
			}
		}
	}
	f[now]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	FR(i,1,m)cin>>cr[i];
	FR(i,1,n){
		ll k;
		cin>>k;
		ll h;
		FR(j,1,k){
			ll gt,ti;
			cin>>gt>>ti;
			sta[gt][i]=ti;
			if(j>1){
				node w;
				w.op=i,w.nxto=gt;
				u[h].push_back(w);
				w.nxto=h;
				u[gt].push_back(w);
			}
			h=gt;
		}
	}
	FR(i,1,M-5){
		FR(j,1,M-5){
			tim[i][j]=-1;
		}
	}
	FR(i,1,n){
		dfs(i,i,0,0);
	}
	FR(i,1,q){
		int x,y;
		cin>>x>>y;
		cout<<tim[x][y]+cr[x]+cr[y]<<endl; 
	}
	return 0;
}
