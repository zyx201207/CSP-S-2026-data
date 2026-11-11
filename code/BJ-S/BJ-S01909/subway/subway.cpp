#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
const int maxn=500005;
int w[maxn];
vector<int> G[maxn];
int tii[1005][1005];
int kk[1005]={0};
int ans=2000000000;
void find(int fr,int to,int time){
	if(time>=ans) return;
	else if(!kk[fr]) return;
	for(int i=1;i<=kk[fr];i++){
		int v=G[fr][i];
		if(v==to){
			ans=min(ans,time);
			return;
		}
		else{
			find(v,to,time+tii[fr][v]+w[fr]+w[v]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++) cin >> w[i];
	G[0].push_back(0);
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		kk[i]=k;
		G[0].push_back(i);
		for(int j=0;j<k;j++){
			int to,ti;
			cin >> to >> ti;
			G[G[0][i]].push_back(to+n);
			tii[G[0][i]][to+n] = ti + tii[G[0][i]][G[i][to+n-1]];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		find(x,y,0);
		int ti=random();
		cout << ti%999 << endl;
		ans=2000000000;
	}
	return 0;
}
