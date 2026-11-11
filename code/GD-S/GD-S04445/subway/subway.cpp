#include<bits/stdc++.h>
using namespace std;
int at[1000][60][3],v[1000]={0};
void dfs(int s,int step,int z){
	if(s==z) {
		cout<<step;
		return;
	}
	for(int i=1;i<=v[i];i++){
		dfs(at[s][i][1],step+at[s][i][1],z);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;  //c测试点编号、n地铁线路数、m地铁站数、d地铁站最多被几条线路经过，q出行计划数
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	int w[m+10],k[n+10],xy[q+10][4];
	
	for(int i=1;i<=m;i++) cin>>w[i];  //地铁站的地铁口走到站厅需要的时间
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int t1,t2;
			cin>>t1;
			cin>>t2;
			++v[t1];
			at[t1][v[t1]][1]=i;
			at[t1][v[t1]][2]=t2;
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>xy[i][1];
		cin>>xy[i][2];
		dfs(xy[i][1],w[xy[i][1]]+w[xy[i][2]],xy[i][2]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
