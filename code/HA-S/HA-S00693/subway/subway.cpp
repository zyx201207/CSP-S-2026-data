#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500100];
long long k[520],a[520][500100],t[520][500100];
long long x,y,ans,mn;
long long stop[500100][520],mp[500100][520];
long long num[500100][520];//当前站是第i条线路的第几站 



void dfs(int id,long long time){//当前站， 
	if(id==y){
		if(mn==-1)mn=time;
		else mn=min(mn,time);
	}
	
	for(int i=1;i<=n;i++){
		if(mp[id][i]==1){
			time+=stop[id][i]+t[i][num[id][i]];
			dfs(a[i][num[id][i]+1],time);
		}
	}
}
void aaa(int x,int y){
	ans=w[x]+w[y];
	mn=-1;
	dfs(x,ans);
	cout<<mn<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			stop[a[i][j]][i]=t[i][j];
			mp[a[i][j]][i]=1;
			num[a[i][j]][i]=j;
		} 
	}
	while(q--){
		cin>>x>>y;
		aaa(x,y);
		
		
		
	}
	return 0;
} 
