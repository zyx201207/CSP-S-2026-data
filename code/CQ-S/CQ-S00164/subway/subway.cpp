#include <iostream>
#define int long long
using namespace std;

struct node{
	int len,thd;
};

int c,n,m,d,q;
int w[500005];
node sta[500005][25];
int cnt[500005];
int x[100005],y[100005];
int dist[505][505];

void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++) if(i!=j) dist[i][j]=1e18;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<cnt[i];j++){
			for(int k=j+1;k<cnt[i];k++){
				int p1=sta[i][j].thd,p2=sta[i][k].thd;
				if(dist[p1][p2]>(sta[i][j].len+sta[i][k].len)) dist[p1][p2]=dist[p2][p1]=(sta[i][j].len+sta[i][k].len);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++) if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			sta[a][cnt[a]].len=t;
			sta[a][cnt[a]].thd=i;
			cnt[a]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	} 
	
	floyd();
	
	for(int i=1;i<=q;i++){
		int ans=1e18;
		for(int j=0;j<cnt[x[i]];j++){
			for(int k=0;k<cnt[y[i]];k++){
				int t1=sta[x[i]][j].thd,t2=sta[y[i]][k].thd;
				int l1=sta[x[i]][j].len,l2=sta[y[i]][k].len;
//				cout<<t1<<' '<<t2<<' '<<dist[t1][t2]<<endl;
				if((dist[t1][t2]+l1+l2)<ans) ans=dist[t1][t2]+l1+l2; 
			}
		}
		cout<<ans+w[x[i]]+w[y[i]]<<endl;
	}
	return 0;
}
