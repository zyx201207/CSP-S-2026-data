#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int w[N];//每个地铁站的地铁口走到站厅需要的时间
vector<int>a[N]//a[i][j]第 i 条线路经过的第 j 个地铁站
,t[N];//t[i][j]地铁站的站厅走到第 i 条线路的站台需要的时间
int L[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	memset(L,0x3f3f3f3f,sizeof(L));
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		L[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int _a,_t;cin>>_a>>_t;a[i].push_back(_a);t[i].push_back(_t);
		}
		for(int ii=0;ii<k;ii++){
			for(int jj=ii+1;jj<k;jj++){
				L[a[i][ii]][a[i][jj]]=L[a[i][jj]][a[i][ii]]=min(L[a[i][ii]][a[i][jj]],t[i][ii]+t[i][jj]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(L[i][k]+L[k][j]<L[i][j])L[i][j]=L[i][k]+L[k][j];
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<L[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
