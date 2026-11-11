#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q; 
int a[100001][100001],t[100001][100001],k; 
int w[100001]={}; 
int head[100001]={};
int ans[100001];
/*
void ch(int u,int v){
	
}

void dfs(int u,int v){
		
} 
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cin>>k;
	for(int i=0;i<m;i++){
		cin>>w[i];
		for(int j=0;j<k;j++){
			cin>>a[i][j];
			cin>>t[i][j]; 
		}
	}
	
	cout<<ans[0]; 
	
	return 0;
}

