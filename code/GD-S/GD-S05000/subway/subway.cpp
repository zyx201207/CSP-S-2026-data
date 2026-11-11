/*
对于第 1 个出行计划，小 R 将从第 1 个地铁站前往第 3 个地铁站：他可以先从第
1 个地铁站的地铁口走到站厅，再走到第 1 条线路的站台，乘坐第 1 条线路到达第 2 个
地铁站后走回站厅，再走到第 2 条线路的站台，乘坐第 2 条线路到达第 3 个地铁站后
走回站厅，最后走到第 3 个地铁站的地铁口，总步行时间为
w1 + t1,1 + (t1,2 + t2,2) + t2,3 + w3 = 4 + 5 + (7 + 3) + 4 + 9 = 32.
t1,1 + (t1,2 + t2,2) + t2,3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int Map[m+1][m+1]={};
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j) Map[i][j]=1e6; 
		}
	}
	vector<int> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		int a[x+1]={},t[x+1]={};
		for(int j=1,y,z;j<=x;j++){
			cin>>a[j]>>t[j];
			//cin>>y>>z;
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<=x;k++){
				if(a[j]!=a[k]){
					Map[a[j]][a[k]]=Map[a[k]][a[j]]=min(Map[a[j]][a[k]],t[j]+t[k]);
				}
			}
		}
	}

	
	// djs
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(Map[i][j]>Map[i][k]+Map[k][j]){
					Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}
	}
	int start,end;
	while(q--){
		cin>>start>>end;
		cout<<Map[start][end]+w[start]+w[end]<<'\n';
	}
	return 0;
//	cout<<Map[1][5];
}
