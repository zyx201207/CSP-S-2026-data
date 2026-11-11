#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int c,n,m,d,q,w[N],k[N],a[N][N],t[N][N];
int dfs(int b,int e){
	int num=0;
	for(int i=1;i<=k[b];i++){
		num+=w[i]+t[i][i];
		dfs(a[b][i],a[a[b][i]][i]);
	}
	return num;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	while(q--){
		int B,E;
		cin>>B>>E;
		cout<<dfs(B,E)<<endl;
	}
}
