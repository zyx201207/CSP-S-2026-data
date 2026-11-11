//中央民族大学附属中学贵阳学校 GZ-S00152 张诗苑 
#include<bits/stdc++.h>
using namespace std;

const int N=505;
const int M=500000+10;
const int INF=0x3f3f3f3f;
int idx,n,m,d,q;

int t[N][M];
int o[M];

vector<int> zxb[M];  
int js[N];
long long lj[N][N];

void c(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) lj[i][j]=(i==j)?0:INF;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>idx>>n>>m>>d>>q;
	c();
	
	for(int i=1;i<=m;i++) cin>>js[i];
	int a,r;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>r;
			zxb[a].push_back(i);
			o[a]++;
			t[i][a]=r;
		}
	}
	
	for(int i=1;i<=m;i++){
		vector<int> nw;
		int cnt=0;
		for(int v=0;v<o[i];v++){
			for(int u=0;u<cnt;u++){
				int vi=zxb[i][v],ui=nw[u];
				lj[vi][ui]=min(lj[vi][ui],(long long)t[ui][i]+t[vi][i]);
				lj[ui][vi]=lj[vi][ui];
			}
			nw.push_back(zxb[i][v]);
			cnt++;
		}
	}
	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j && lj[i][k]+lj[k][j]<lj[i][j]) {
					
					lj[i][j]=lj[i][k]+lj[k][j];
					
				}
			}
		}
	} 
	
	
	int x,y;
	long long ans,mi;
	while(q--){
		mi=INF;
		cin>>x>>y;
		for(int v=0;v<o[x];v++){
			for(int u=0;u<o[y];u++){
				ans=lj[zxb[x][v]][zxb[y][u]];
				ans+=t[zxb[x][v]][x]+t[zxb[y][u]][y];
				mi=min(ans,mi);
			}
		}
		mi+=js[x]+js[y];
		cout<<mi<<endl;
	}
	return 0;
}
