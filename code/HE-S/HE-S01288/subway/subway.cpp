#include<bits/stdc++.h>
using namespace std;
queue<int>qe;
int n,m,c,d,q,k,s,e,ans,maxn,w[510],a[1050],t[1050],dp[1050][1050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	scanf("%d",&k);
	for(int i=1;i<=k*n;i++){
		cin>>a[i]>>t[i];
		dp[i][a[i]]=t[i]+w[i];
	}
	while(q--){
		scanf("%d%d",&s,&e);
		while(dp[s][e]!=x){
			for(int i=1;i<=n;i++){
				if(dp[i][e])s=i;
			}
		}
	}
	return 0;
}
