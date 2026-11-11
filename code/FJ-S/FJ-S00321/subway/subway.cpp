#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,xl[500010];
long long lt[500010][510];
struct wyw{
	long long w;
	int l,lj[510],zx[510];
};
wyw fx[500010];
struct zh{
	int st,ed;
};
zh lyx[100010];
struct ans{
	int x,z;
};
queue<ans> qp;
queue<long long> en;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>fx[i].w;
	}
	for(int i=1;i<=n;++i){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>xl[j]>>lt[xl[j]][i];
			fx[xl[j-1]].lj[++fx[xl[j-1]].l]=xl[j];
			fx[xl[j-1]].zx[fx[xl[j-1]].l]=i;
		}
	}
	for(int i=1;i<=q;++i){
		cin>>lyx[i].st>>lyx[i].ed;
		qp.push({lyx[i].st,0});
		en.push(0);
		long long hd=0;
		while(!qp.empty()){
			struct ans t=qp.front();
			long long g=en.front();
			en.pop();
			qp.pop();
			if(t.x==lyx[i].ed){
				hd=min(hd,g);
				continue;
			}
			for(int j=1;j<=fx[t.x].l;++j){
				if(t.z==fx[t.x].zx[j]){
					qp.push({fx[t.x].lj[j],t.z});
					en.push(g);
				}else{
					qp.push({fx[t.x].lj[j],fx[t.x].zx[j]});
					en.push(g+fx[t.x].w+lt[t.x][fx[t.x].zx[j]]);
				}
			}
		}
		cout<<hd<<endl;
	}
	return 0;
}

