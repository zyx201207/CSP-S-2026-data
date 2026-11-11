#include<bits/stdc++.h>
using namespace std;
struct p{
	long long l,r;
};
struct pp{
	long long o,p,kq;
};
bool u[500005];
long long n,an,m,c,y,g,h,d,q,w[500005],aa,bb,ct;
vector<p> v[500005];
int ty[1005][505];
void dfs(long long xx,long long yy,long long zz){
		if(xx==h){
			an=min(an,yy+w[g]+ty[h][zz]+w[h]);
			return;
		}
		for(int i=0;i<int(v[xx].size());i++){
			if(!u[v[xx][i].l]){
				u[v[xx][i].l]=1;
				if(v[xx][i].r!=zz){
					dfs(v[xx][i].l,yy+ty[xx][zz]+ty[xx][v[xx][i].r],v[xx][i].r);
				}else{
					dfs(v[xx][i].l,yy,zz);
				}
				u[v[xx][i].l]=0;
			}
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>y;
		for(int j=1;j<=y;j++){
			cin>>aa>>bb;
			if(j>1){
				v[aa].push_back({ct,i});
				v[ct].push_back({aa,i});
			}
			ct=aa;
			ty[aa][i]=bb;
		}
	}
	for(int i=1;i<=q;i++){
		memset(u,0,sizeof(u));
		cin>>g>>h;
		u[g]=1;
		an=9e18;
		dfs(g,0,0);
		cout <<an<<endl;
	}
	return 0;
}
