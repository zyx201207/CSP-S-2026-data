#include<bits/stdc++.h>
using namespace std;
//¿ªlong long,freopen!!!
long long ccc,n,m,d,Q,w[505],k[505],dis1[505][505],dis2[505][505],inf=0x3f3f3f3f3f3f3f3f;
vector<long long> a[505],t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			for(int l=1;l<j;l++){
				if(dis2[a[i][l]][a[i][j]]==0) dis2[a[i][l]][a[i][j]]=inf;
				dis2[a[i][l]][a[i][j]]=min(dis2[a[i][l]][a[i][j]],t[i][j]+t[i][l]);
				dis2[a[i][j]][a[i][l]]=dis2[a[i][l]][a[i][j]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			dis1[i][j]=inf;
			if(dis2[i][j]==0)
				dis2[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
				dis1[i][j]=min(dis1[i][j],dis2[i][j]+w[i]+w[j]);
				dis2[j][i]=dis2[i][j];
				dis1[j][i]=dis1[i][j];
			}
		}
	}
	while(Q--){
		long long l,r;
		cin>>l>>r;
		cout<<dis1[l][r]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
