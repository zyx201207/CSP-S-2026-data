#include<bits/stdc++.h>
using namespace std;
const int L=5e5+5;
int c,n,m,d,q,cnt;
int book[L];
bool boos[505];
int mapp[505][L];
int mmap[505][L];
struct estation{
	int w;
	int k;
	int canto[20];
	int howto[20];
}est[L];
void dfs(int x,int y,int s){
	if(x==0 || s>book[x]) return;
	book[x]=s;
	if(x==y){
		cnt=s;
		return;
	}
	for(int i=0;i<est[x].k;i++){
		int p=est[x].canto[i],t=est[x].howto[i];
		if(boos[p]){
			boos[p]=false;
			for(int j=1;j<=mapp[p][0];j++) dfs(mapp[p][j],y,s+t+mmap[p][j]);
			boos[p]=true;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ont","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>est[i].w;
	for(int i=1;i<=n;i++){
		mapp[i][i]=-1;
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			est[a].canto[est[a].k]=i;
			est[a].howto[est[a].k++]=t;
			mapp[i][++mapp[i][0]]=a;
			mmap[i][mapp[i][0]]=t;
		}
	}
	while(q--){
		int s,e,t=INT_MAX;
		cnt=0;
		for(int i=1;i<=m;i++) book[i]=INT_MAX;
		for(int i=1;i<=n;i++) boos[i]=true;
		cin>>s>>e;
		dfs(s,e,0);
		cout<<est[s].w+cnt+est[e].w<<'\n';
	}
	return 0;
}
