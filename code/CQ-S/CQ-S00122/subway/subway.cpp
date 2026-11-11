#include<bits/stdc++.h>
using namespace std;
long long w[500001];
bool pd[501],pdd[500001];
long long ans=1e18;
struct node{
	long long v,w;
};
vector<node>v[501];
vector<long long>vr[500001];
void bfs(int ed,int mid,long long anss){
	if(mid==ed){
		ans=min(anss,ans);
		return;
	}
	if(anss>ans) return;
	if(pdd[mid]){
		return;
	}
	pdd[mid]=1;
	int si=vr[mid].size();
	for(int i=0;i<si;i++){
		int siz=v[vr[mid][i]].size();
		if(pd[vr[mid][i]]) continue;
		pd[vr[mid][i]]=1;
		for(int j=0;j<siz;j++){
			bfs(ed,v[vr[mid][i]][j].v,anss+v[vr[mid][i]][mid].w+v[vr[mid][i]][j].w);
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			v[i].push_back({a,t});
			vr[a].push_back(i);
		}
	}
	for(int ce=1;ce<=q;ce++){
		for(int i=0;i<=500;i++) pd[i]=0;
		for(int i=0;i<=500000;i++) pdd[i]=0;
		ans=1e18;
		int x,y;
		cin>>x>>y;
		bfs(y,x,w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
