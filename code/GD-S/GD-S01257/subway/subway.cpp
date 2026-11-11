#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct dt{
	int k;
	int a[1005],t[1005];
}xl[505];
int e[1005][1005];
int x,y;
int bjzd[500005];
int bjxz[200005][505];
long long minx=1e18;
void dfs(int st,long long sz,int xz,int xb){
	if(st==y){
		minx=min(minx,sz+xl[xz].t[xb]+w[y]);
	}
	if(bjzd[st]==0){
		bjzd[st]=1;
		//cout<<st<<" "<<sz<<" "<<xz<<"\n";
	}
	else {
		return;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<xl[i].k;j++){
			if(xl[i].a[j]==st&&bjxz[xl[i].a[j]][i]==0){
				bjxz[xl[i].a[j]][i]=1;
				if(xz!=i){
					dfs(xl[i].a[j+1],sz+xl[xz].t[xb]+xl[i].t[j],i,j+1);
				}
				else {
					dfs(xl[i].a[j+1],sz,i,j+1);
				}
				bjzd[st]=0;
				bjxz[xl[i].a[j]][i]=0;
				
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=xl[i].k;j>=2;j--){
			if(xl[i].a[j]==st&&bjxz[xl[i].a[j]][i]==0){
				bjxz[xl[i].a[j]][i]=1;
				if(xz!=i){
					dfs(xl[i].a[j-1],sz+xl[xz].t[xb]+xl[i].t[j],i,j-1);
				}
				else {
					dfs(xl[i].a[j-1],sz,i,j-1);
				}
				bjzd[st]=0;
				bjxz[xl[i].a[j]][i]=0;
				
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>xl[i].k;
		for (int j=1;j<=xl[i].k;j++){
			cin>>xl[i].a[j]>>xl[i].t[j];
		}
	}
	//cout<<xl[13].
	while(q--){
		minx=1e18;
		for (int i=1;i<=m;i++){
			bjzd[i]=0;
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				bjxz[i][j]=0;
			}
		}
		cin>>x>>y;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=xl[i].k;j++){
				if(xl[i].a[j]==x){
					dfs(x,w[x]+xl[i].t[j],i,j);
				}
			}
		}
		cout<<minx<<"\n";		
	}
	return 0;
} 
