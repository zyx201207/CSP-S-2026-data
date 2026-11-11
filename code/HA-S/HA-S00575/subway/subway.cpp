#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[410],b[410][410],ans[100010],len;
//long long val[M],to[M],nxt[M],h[N]
/*void add(long long x,long long y,long long z){
	val[++cnt]=z;
	to[cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j) b[i][j]=1e9*4+10;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k,t[410]={0},tt[410]={0},cnt=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long y,z;
			cin>>y>>z;
			t[++cnt]=y;
			tt[cnt]=z;
			for(int l=1;l<cnt;l++){
				b[t[l]][y]=b[y][t[l]]=min(b[t[l]][y],z+tt[l]);
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				b[i][j]=b[j][i]=min(b[i][j],b[i][l]+b[l][j]);
			}
		}
	}
	/*cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}*/
	/*for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		long long dis[20010]={0};
		bool b[20010]={0}; 
		for(int j=1;j<=m;j++){
			if(j!=x) dis[j]=4*1e9+10;
		}
		for(int j=1;j<=m;j++){
			long long minn=4*1e9+10,minx=1;
			for(int k=1;k<=m;k++){
				if(!b[k]&&minn>dis[k]){
					minn=dis[k];
					minx=k;
				}
			}
			b[minx]=1;
			for(int k=1;k<=m;k++){
				if(!b[k]){
					dis[k]=min(dis[k],dis[minx]+w[minx]+b[minx][])
				}
			} 
		}
	}*/
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		ans[++len]=b[x][y]+w[x]+w[y];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
