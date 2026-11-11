#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1001];
int k;
int a[1001][1001];
int t[1001][1001];
int x[1001];
int y[1001];

int dfs(int step,int i,int j){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			cin>>x[i]>>y[j];
		}
	}
	int nums=0;
	while(q--){
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
