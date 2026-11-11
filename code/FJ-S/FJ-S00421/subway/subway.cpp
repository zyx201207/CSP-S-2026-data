#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,T,ww[500005],ans[1005];
int bj[1005];
int e[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			e[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		int a[k],t[k];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(a[l]==a[j]) continue;
				e[a[l]][a[j]]=min(t[l]+t[j],e[a[l]][a[j]]);
				e[a[j]][a[l]]=min(t[l]+t[j],e[a[j]][a[l]]);
			}
		}
	}
	while(T--){
		int u=0,v=0;
		for(int i=1;i<=1000;i++){
			bj[i]=0;
		}
		for(int i=1;i<=1000;i++){
			ans[i]=1e18;
		}
		cin>>u>>v;
		
		priority_queue<pair<int,int>> q;
		
		q.push({0,u});
		while(q.size()!=0){
			int t=q.top().second,w=-q.top().first;
			q.pop();
			if(bj[t]==1) continue;
			bj[t]=1;
			if(t==v){
				cout<<w+ww[u]+ww[v]<<endl;
				break;
			}
			for(int i=1;i<=m;i++){
				if(e[t][i]==1e18||bj[i]==1){
					continue;
				}else if(e[t][i]+w<ans[i]){
					ans[i]=e[t][i]+w;
					q.push({-(e[t][i]+w),i});
				}
			}
		}
	}
	return 0;
}
