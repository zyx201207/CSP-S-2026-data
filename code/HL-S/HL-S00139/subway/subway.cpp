#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int w[maxn];
int k[maxn];
int a[510][maxn];
int t[510][maxn];
bool A=true;
bool B=true;
int dp[510];
int f[maxn][3];
int sum[maxn];
int h[maxn];
int list[510][510];

int dijkstra(int x,int y){
	int r=1;
	for(int i=1;i<=510;i++){
		if(i==x) h[i]=0;
		h[i]=1e9;
	}
	for(int i=1;i<=510;i++){
		if(f[x][i]!=0 && i!=x){
			h[i]=min(h[i],)
		}
	}
}


int main(){
	int c,n,m,d,Q;
	cin >> c >> n >> m >> d >> Q;
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	
	for(int i=1;i<=n;i++){ //地铁信息，i号线 
		cin >> k[i];
		if(k[i]>2) A=false;
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			sum[a[i][j]]++;
			list[a[i][j]][sum[a[i][j]]]=i;
			if(j==2){
				f[a[i][j-1]][a[i][j]]=t[i][j-1]+t[i][j];
				f[a[i][j]][a[i][j-1]]=t[i][j-1]+t[i][j];
			}
		}
	}//f bianquan已确定 
	int x,y; 
	for(int q=1;q<=Q;q++){
		if(A){
			cin >> x >> y;
			
		}
		if(B){
			cin >> x >> y;
		}
	}
	return 0;
}
