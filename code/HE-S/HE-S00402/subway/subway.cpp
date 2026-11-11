#include<bits/stdc++.h>
using namespace std;
int n,m,w[500005];
int a[500][500005][3];
vector<int> go[500005];
vector<int> goo[505];
int d,q,c,k;
int u,r;
int ans;
int tem;
void dfs(int x,int y,int xi,int st){
	if(x==y){
		ans=min(ans,st);
		ans+=w[y]-a[xi][x][1];
		return;
	}
	for(int i=1;i<=a[xi][x][2];i++){//zhan
		for(int j=0;j<=goo[i].size();j++){//xian
			dfs(i,y,j,st+a[xi][i][1]+a[j][i][1]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){//n各线路 
		cin>>k;
		for(int j=1;j<=k;j++){//i线k个站 
			cin>>a[i][j][0]>>a[i][j][1];
			a[i][j][2]=k;
			go[i].push_back(a[i][j][0]);//i xian tong zhan
			go[a[i][j][0]].push_back(i);
			goo[j].push_back(i);//j站通i线 
		}
	}

	for(int i=1;i<=q;i++){
		cin>>u>>r; 
		if(c>=12 && c<=19){
			cout<<w[u]+w[r]+a[u][1][1]*(abs(r-u)/2)<<endl;
		}
		else{
			ans=w[r];
			for(int it=0;it<=goo[u].size()-1;it++){//xian
				dfs(u,r,goo[u][it],0);
				
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

