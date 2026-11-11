#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
int c,n,m,d,b;
int h[1001];
int die[1001][1001];
int l[1001][1001];
void floyd(){
	for(int u=1;u<=2;u++)
	for(int i=1;i<=m+n;i++){
		for(int k=1;k<=n+m;k++){
			for(int j=1;j<=m+n;j++){
				if(i==j||j==k||i==k) continue;
				if(l[i][k]+l[k][j]<die[i][j]) die[i][j]=l[i][k]+l[k][j];
				if(die[i][k]+die[k][j]<die[i][j]) die[i][j]=die[i][k]+die[k][j];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>b;
	for(int i=1;i<=n+m;i++) for(int j=1;j<=m+n;j++){
		die[i][j]=N;
		if(i!=j) l[i][j]=N;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&h[i]);
	}
	int u,v,w;
	for(int i=1;i<=n;i++){
		cin>>u;
		for(int j=1;j<=u;j++){
			scanf("%d %d",&v,&w);
			l[i+m][v]=w;
			l[v][i+m]=w;
		}
	}
	floyd();
	int o,p;
	for(int i=1;i<=b;i++){
		scanf("%d %d",&o,&p);
		printf("%d\n",die[o][p]+h[o]+h[p]);
	}
	return 0;
}
