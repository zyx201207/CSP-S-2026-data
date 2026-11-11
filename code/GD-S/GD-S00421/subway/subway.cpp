#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "subway"
int c,n,m,d,q,k,esti[505],rds[505][505][2],pla[100005][2],dist[505][505];
queue<int> fdw;
void flyd(){
	for(int i=1;i<m;i++){
		for(int j=1;j<m;j++){
			for(int k=1;k<m;k++){
				if(dist[i][k]!=1145141919810&&dist[k][j]!=1145141919810){
					dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
				}
			}
		}
	}
	return ;
}
signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	for(int i=0;i<=505;i++){
		for(int j=0;j<=505;j++){
			dist[i][j]=1145141919810;
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>esti[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int tow,t;
			cin>>tow>>t;
			rds[i][tow][0]=1;
			dist[i][tow]=t;
			rds[i][tow][1]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(rds[i][j][0]=1&&j!=i){
				dist[i][j]+=rds[i][i][1];
			}

		}
	}
	//for(int j=1;j<=m;j++){
	//	if(dist[pla[i][0]][j]==1145141919810) continue;
	//		//for(int k=1;k<=m;k++){
	//	dist[pla[i][0]][pla[i][1]]=min(dist[pla[i][0]][pla[i][1]],dist[pla[i][0]][j]+dist[j][pla[i][1]]);
	//}
	for(int i=1;i<=q;i++){
		cin>>pla[i][0]>>pla[i][1];
	}
	flyd();
	for(int i=1;i<=q;i++){
		cout<<dist[pla[i][0]][pla[i][1]]+esti[pla[i][0]]+esti[pla[i][1]]<<endl;
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
LUV ME! LUV ME! --+++-+
HATE ME! HATE ME! --+++-+
LUV ME! LUV ME! +=--
KILL ME! KILL ME!
*/
