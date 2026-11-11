#include<bits/stdc++.h>//咕咕咕咕咕 
using namespace std;

long long c,n,m,d,q; //m地铁站-5*10^5  n线路- 500
long long a[25][500005],t[25][500005],w[500005],k[500005];
long long x,y;

struct STA{
	long long u,v,w;
};
STA Vec[500005];
long long VecL=0; 
long long ap[1005][1005];

void djs(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ap[i][j]=99999999;
		}
	}
	for(int i=1;i<=VecL;i++){
		ap[Vec[i].u][Vec[i].v]=Vec[i].w;
		ap[Vec[i].v][Vec[i].u]=Vec[i].w;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			for(int k=1;k<=m;k++){
				if(j==k) continue;
				if(i==k) continue;
				ap[i][j]=min(ap[i][j],ap[i][k]+ap[k][j]);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){ //i线路 j铁站
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(long long l1=1;l1<=k[i];l1++){
			for(long long l2=1;l2<=k[i];l2++){
				long long w=t[i][a[i][l1]]+t[i][a[i][l2]];
				
				STA S1,S2;
				S1.u=a[i][l1];S1.v=a[i][l2];S1.w=w;
				S2.u=a[i][l2];S2.v=a[i][l1];S2.w=w;
				
				Vec[VecL+1]=S1;
				Vec[VecL+2]=S2;
				VecL+=2;
			}
		} 
		
	}
	
	while(q--){
		cin>>x>>y;
		djs();
		cout<<ap[x][y]+w[x]+w[y];
	}
	return 0;
}
