#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[20005];
int mnx[20005][20005];
void init(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int k,a[20005],t[20005];
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[a[i]];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(t[a[i]]+t[a[j]]<mnx[a[i]][a[j]])mnx[a[i]][a[j]]=t[a[i]]+t[a[j]];
		}
	}
	return;
}
int main(){
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			mnx[i][j]=0x3f3f;
			if(i==j)mnx[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		init();
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				mnx[i][j]=min(mnx[i][j],mnx[i][k]+mnx[k][j]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+mnx[x][y]+w[y]<<endl;
	}
	return 0;
}

