#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][500005];
int t[505][500005];
int k[505];
int s[500005][22];
int nub[500005];
struct tme{
	int p;
	int ti;
};
bool fid1(int x,int y){
	int lx=nub[x],ly=nub[y];
	for (int i=1;i<=lx;i++){
		for (int j=1;j<=ly;j++){
			if (s[x][i]=s[y][j]){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			nub[a[i][j]]++;
			s[a[i][j]][nub[a[i][j]]]=k[i];
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if (fid1(x,y)){
			cout<<w[x]+w[y]<<endl;
			continue ;
		}
		queue<tme> g;
		g.push({x,w[x]});
		bool vis[505]={0};
		int ans=0;
		while (!g.empty()){
			tme e=g.front();
			g.pop();
			if (fid1(e.p,y)){
				ans=(ans==0)?e.ti+w[y]:min(ans,e.ti+w[y]);
			} 
			for (int i=1;i<=nub[e.p];i++){
				int ki=s[e.p][i];
				for (int j=1;j<=k[ki];j++){
					if (nub[j]>1){
						for (int j1=1;j1<=nub[j];j1++){
							if (s[j][j1]!=ki&&vis[s[j][j1]]==0){
								g.push({j,e.ti+t[j][j1]+t[j][ki]});
							}
						}
					}
				}
				vis[ki]=1;
			}
			
		}
		cout<<ans<<endl;
	}
	
}
