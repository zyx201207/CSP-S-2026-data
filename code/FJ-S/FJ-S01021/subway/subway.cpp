#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int c,n,m,d,q;
int ans=1e9;
int w[N],k[505],yr,xr;
int a[505][N],t[505][N],vis[N],v[N];
vector<pair<int,int>>g[N];
void bfs(int x,int sum,int jy){
	if(x==yr){
		for(int i=1;i<=k[jy];i++){
			if(a[jy][i]==yr){
				sum+=w[yr]+t[jy][i];
				break;
			}
		}
		ans=min(ans,sum);
		return;
	}
	int len=0;
	for(auto i:g[x]){
		int fir=i.first;
		int sec=i.second;
		if(vis[fir]==1)continue;
		int p=sum;
		if(v[fir]>1){
			for(int j=1;j<=k[sec];j++){
				if(a[sec][j]==fir&&fir!=yr){
					sum+= t[sec][j];
				}
			}
		}
		if(len>=1){
			for(int j=1;j<=k[sec];j++){
				if(a[sec][j]==x){
					sum+= t[sec][j];
				}
			}	 
		}
		vis[fir]=1;
		bfs(fir,sum,sec);
		vis[fir]=0;
		sum=p;
		len++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]]++;
			if(j!=1){
				g[a[i][j]].push_back(make_pair(a[i][j-1],i));
				g[a[i][j-1]].push_back(make_pair(a[i][j],i));
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xr>>yr;
		vis[xr]=1;
		int p=0,pj=0;
		for(int j=1;j<=n;j++){
			for(int kk=1;kk<=m;kk++){
				if(a[j][kk]==xr){
					p=t[j][kk];
					pj=j;
				}
			}
		}
		bfs(xr,w[xr]+p,pj);
		cout<<ans<<endl;
		ans=1e9;
		vis[xr]=0;
	}
	
	return 0;
} 
