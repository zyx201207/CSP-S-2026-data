#include<bits/stdc++.h>
using namespace std;

const int N=510,M=500010;


int c,n,m,d,q;
int a[N][M],w[M];
int k[M],t[M][M];
int x,y;
int ne[M],h[M],idx,e[M],we[M];

void ad(int a, int b,int k1,int j1,int j2){
	ne[idx]=h[a],e[idx]=b,we[idx]=w[a]+w[b]+t[k1][j1]+t[k1][j2],h[a]=idx++;
}



void buit(int k1){
	for(int i=1;i!=0x3f3f3f3f;i++){
		if(i!=1){
			ad(k[i-1],k[i],k1,t[k1][i-1],t[k1][i]);
			ad(k[i],k[i-1],k1,t[k1][i],t[k1][i-1]);
			}
	}
}


int Finding(int x,int y){
	int res=0;
	 
	for(int i=h[x];i!=-1;i=ne[i]){
		int j=e[i];
		res+=w[j];
		
		
	}
	return res;
}
	



int main(){
	
	for(int i=0;i<=N;i++){
			k[i]=0x3f3f3f3f;
	}
	memset(ne,-1,sizeof ne);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
		
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			buit(k[i]);
		}
		
	}
	
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<Finding(x,y)<<endl;
	}
	
	return 0;
}
