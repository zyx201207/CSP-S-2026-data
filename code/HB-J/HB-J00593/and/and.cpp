#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[200009],a[200009];
bool dx[200009];
int ans;
int ygh(int g,int r,int dc){
	if(g>=m){
		if(r>ans&&g==m){
			ans=r;
		}
		return 0;
	}
	dx[dc]=1;
	for(int i=1;i<=n;i++){
		if(dx[i]==1){
			continue;
		}
		ygh(g+1,int(r&a[i]),i);
	}
	dx[dc]=0;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		ygh(1,a[i],i);
	}
	cout<<ans;
	return 0;
}
