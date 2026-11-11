#include<bits/stdc++.h>
using namespace std;
const int N=555,M=5e5+50;
int n,c,d,q,m,k[N],x,y,visb[N],visd[M];
long long w[M],ans;
int sfz[M][N];
vector<int> a[N];
vector<long long>f[N];
void dfs(long long ti,int czh){
	if(czh==y){
		ans=min(ans,ti);
		return ;
	}
	if(ti>=ans){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(sfz[czh][i]!=0&&visb[i]!=q){
			visb[i]=q;
			for(int j=1;j<=k[i];j++){
				if(visd[a[i][j]]!=q){
					visd[a[i][j]]=q;
					dfs(ti+f[i][sfz[czh][i]]+f[i][j],a[i][j]);
					visd[a[i][j]]=0;
				}
			}
			visb[i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+5,0);
		f[i].resize(k[i]+5,0);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>f[i][j];
			sfz[a[i][j]][i]=j;
		}
	}
	while(q){
		ans=LLONG_MAX;
		cin>>x>>y;
		visd[x]=q;
		dfs(0,x);
		cout<<(ans+w[x]+w[y])<<'\n';
		q--;
	}
	return 0;
}
