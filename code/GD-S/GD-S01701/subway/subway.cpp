#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,ko[500005],jia[500005],x,y;
long long tin[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> ko[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
		cin >> x >> y;
		jia[x]=y;
	}
	for(int j=1;j<=m;j++){
		if(jia[j]!=0){
		for(int k=j+1;k<=m;k++){
			if(jia[k]!=0 && tin[j][k]<jia[j]+jia[k]){
			tin[j][k]=jia[j]+jia[k];
			tin[k][j]=jia[j]+jia[k];
			}
		}
		}
	}
	for(int j=1;j<=m;j++)jia[j]=0;
	//所有台已经转移到厅
	}



		for(int j=1;j<=m;j++){
		for(int k=j+1;k<=m;k++){
			if(tin[j][k]==0)tin[j][k]=max(tin[j-1][k]+tin[j-1][j],tin[j][k-1]+tin[k-1][k]);
		}
	}






	while(q--){
		int a,b;
		cin >> a >> b;
		cout << tin[a][b]+ko[a]+ko[b];
}
	//处理厅
	return 0;
}
