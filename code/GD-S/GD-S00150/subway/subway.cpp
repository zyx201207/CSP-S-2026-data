#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll c,n,m,d,q,w[500002],k[502],a[502][22],t[502][22];
/*
n:地铁线路数
m:站点数
d:每个站最多有几条地铁经过
q:询问数 
*/

bool visited[13]; ll minn[13];
ll dfs_ans=0x3f3f3f3f;
void dfs(int start,int end,int pt, int tot){
	if(pt==start)return;
	if(pt==end){
		dfs_ans=min(dfs_ans,tot);
		return;
	}
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//萨伯薇先生 
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i)cin>>w[i];
	for(int i=1; i<=n; ++i){
		cin>>k[i];//经过地铁i号线经过站点数量 
		for(int j=1; j<=k[i]; ++j){
			cin>>a[i][j]>>t[i][j];
			//从站a[i][j]的站厅到地铁i号线站台的时间为t[i][j] 
		}
	}
	if(c>=1&&c<=3){
		
	} 
	
	return 0;
}
/*

*/


































//

