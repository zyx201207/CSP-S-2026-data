//GZ-S00300 付滨诚 贵阳一中 
/*
第二题依旧是图论啊
刚开始以为是分层图 
但当我简单的推一下后发现这很明显是一道最短路 
进站和出站时间我们是可以确定的
而且坐车不要时间 
那我们唯一需要的就是换乘时间 
我们把每条线路看成一个点，两个站台间的时间花费就是边权
这里的d最多20条直接跑Floyd就可以了
特殊情况：
处于一条线不用换乘
若终点或起点是换乘点需要找出发点或结束点所有可能的换乘情况的最小值 
理论可行
实践开始 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int K=2e4+10,N=514;
int c,n,m,d,q,w[N],t[K][21],vis[N],cnt,t1,e[N],a[N],b[N],aaa[N],cnt1;//vis:有几条线了 
long long dist[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,aa,tt;
		cin>>k;
		t1++;
		for(int j=1;j<=k;j++){
			cin>>aa>>tt;
			aaa[++cnt1]=aa;
			vis[aa]++;
			t[aa][t1]=tt;//点aa在t1条线的花费
//			cout<<aa<<" "<<tt<<endl;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=3;j++){
//			cout<<t[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=m;i++){
		if(vis[i]>1){
			e[++cnt]=i;
			for(int j=1;j<=n;j++){
				if(t[i][j]==0) continue;
				for(int k=j+1;k<=n;k++){
					if(t[i][k]==0) continue;
					dist[j][k]=t[i][j]+t[i][k];
					dist[k][j]=t[i][j]+t[i][k];
				}
			} 
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if(v==u) continue;
			for(int k=1;k<=n;k++){
				if(k==u||k==v) continue;
				dist[u][v]=min(dist[u][v],dist[u][k]+dist[k][v]);
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		for(int j=1;j<=cnt;j++){
//			cout<<dist[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(vis[x]==1&&vis[y]==1){
			int xxx=0,yyy=0;
			for(int i=1;i<=n;i++){
				if(t[x][i]) xxx=i;
				if(t[y][i]) yyy=i;
			}
			if(xxx==yyy) cout<<w[x]+w[y]+t[x][xxx]+t[y][yyy]<<"\n";
			else cout<<w[x]+w[y]+t[x][xxx]+t[y][yyy]+dist[xxx][yyy]<<"\n";
		}
		else{
			int cnta=0,cntb=0;
			long long ans=1e18;
			for(int i=1;i<=n;i++){
				if(t[x][i]){
					a[++cnta]=i;
				}
				if(t[y][i]){
					b[++cntb]=i;
				}
			}
			bool f=1;
			for(int i=1;i<=cnta;i++){
				for(int j=1;j<=cntb;j++){
					if(a[i]==b[j]){
						cout<<w[x]+w[y]+t[x][a[i]]+t[y][b[j]]<<"\n";
						f=0;
						break;
					}
				}
				if(!f) break;
			}
			if(f){
				for(int i=1;i<=cnta;i++){
					for(int j=1;j<=cntb;j++){
						ans=min(ans,w[x]+w[y]+t[x][a[i]]+t[y][b[j]]+dist[a[i]][b[j]]);
					}
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
