#include<bits/stdc++.h>
using namespace std;
int c,n,d,begin,end;
long long m,q;
long long w[50005];
long long t[505][25];
long long a[505][25];
int k[505];
int zt[505][505];//zt[i][j]表示i中有的站台坐标 
int tz[505];
int dp[505][505];
bool pd[505][505];
int gs[505];
int cs=0;
long long bfs(int now,int e,long long ma){
	cout<<cs++;
//	if(gs[now]==0)return 0;
//	if(now==e)return ma;
//	long long be=0;
//	for(int i=1;i<=gs[now];i++){
//		long long xxx=bfs(zt[begin][i],e,ma+t[now][zt[begin][i]]);
//		cout<<"xxx"<<xxx<<"\n";
//		if(xxx>be){
//			be=xxx;
//		}
//	}
	return cs;
}
void work(){
	cin>>begin>>end;
	cout<<w[begin]+t[begin][begin]+w[end]+t[begin][end]<<"\n";
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","d",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>a[i][1]>>t[i][1];
		for(int j=2;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dp[a[i][j-1]][a[i][j]]=t[i][j-1];
			zt[a[i][j-1]][++tz[a[i][j-1]]]=a[i][j];
			pd[a[i][j-1]][a[i][j]]=1;
			gs[a[i][j-1]]++;
		}	
	}
	for(int i=1;i<=q;i++){
		work();
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
