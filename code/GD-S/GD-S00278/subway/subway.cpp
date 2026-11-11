#include <bits/stdc++.h>
using namespace std;
long long w[500005];
long long a[1005][1005],t[1005][1005],dis[1005][1005];
long long n,m,d,q;
void floyd(){
	for(long long k=1;k<=m;k++){
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void work1(){
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(long long u=1;u<=k;u++){
			dis[a[i][u]][a[i][u]]=0;
			for(long long v=u+1;v<=k;v++){
				dis[a[i][u]][a[i][v]]=t[i][u]+t[i][v];
				dis[a[i][v]][a[i][u]]=t[i][u]+t[i][v];
			}
		}
	}
	floyd();
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
}
bool is_inline[5][500005];
long long cnt_inline[500005];
void work2(){
	cin>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			is_inline[i][a[i][j]]=1;
			cnt_inline[a[i][j]]++;
		}
	}
	long long minn=0x3f3f3f3f3f3f3f3f;
	for(long long i=1;i<=m;i++){
		if(cnt_inline[i]==2)minn=min(minn,t[1][i]+t[2][i]);
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		if(cnt_inline[x]<cnt_inline[y])swap(x,y);
		if(cnt_inline[x]==1&&cnt_inline[y]==1){
			if(is_inline[1][x]==1&&is_inline[1][y]==1){
				cout<<w[x]+t[1][x]+t[1][y]+w[y];
				continue;
			}
			if(is_inline[2][x]==1&&is_inline[2][y]==1){
				cout<<w[x]+t[2][x]+t[2][y]+w[y];
				continue;
			}
			if(is_inline[1][x]==1&&is_inline[2][y]==1){
				cout<<w[x]+t[1][x]+minn+t[2][y]+w[y];
				continue;
			}
			if(is_inline[2][x]==1&&is_inline[1][y]==1){
				cout<<w[x]+t[2][x]+minn+t[1][y]+w[y];
				continue;
			}
		}
		if(cnt_inline[x]==2&&cnt_inline[y]==1){
			if(is_inline[1][y]==1){
				cout<<min(w[x]+t[1][x]+t[1][y]+w[y],w[x]+t[2][x]+minn+t[1][y]+w[y]);
				continue;
			}
			if(is_inline[2][y]==1){
				cout<<min(w[x]+t[2][x]+t[2][y]+w[y],w[x]+t[1][x]+minn+t[2][y]+w[y]);
				continue;
			}
		}
		if(cnt_inline[x]==2&&cnt_inline[y]==2){
			cout<<min(w[x]+t[1][x]+t[1][y]+w[y],w[x]+t[2][x]+t[2][y]+w[y]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c;
	cin>>c;
	if(c<=11)work1();
	else if(c==20||c==21)work2();
}
