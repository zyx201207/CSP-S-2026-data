#include<bits/stdc++.h>
using namespace std;
int m,n,d,q,w[500050],a[550][550][3]s,e,ans1;
void dfs(int st){
	if(st==e){
		ans=min(ans,ans1);
		return;
	}
	if(ans1>ans){
		return;
	}
	for(int i=1;i<=a[st][0][0];i++){
		ans1+=a[st][i][2];
		dfs(a[st][i][1])
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0][0];
		for(int j=1;j<=a[i][0][0];j++){
			cin>>a[i][j][1]>>a[i][j][2];
		}
	}
	for(int i=1;i<=q;i++){
		ans=1e9;
		cin>>s>>e;
		
	}
}
