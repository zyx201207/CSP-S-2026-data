#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q;
char c;int ans;
int a[1005][1005],b[100005],t[1005][1005];
int vis[1005][1005],vis2[1005];
int g(int w,int f){
	for(int i=1;i<=m;i++){
		if(a[w][i]==1&&a[i][f]==1){
			ans+=vis2[w]+vis2[i]+vis2[i]+vis2[f];
			return ans;
		}
		else if(a[w][i]&&!a[i][f]){
			ans+=vis2[w]+vis2[i];
			return g(i,f);
		}
		else if(!a[w][i]&&a[i][f]){
			ans+=vis2[f]+vis2[i];
			return g(i,w);
		}
	}	
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;i<=k;j++){
			cin>>a[j][i]>>t[j][i];
			vis[a[j][i]][a[j-1][i]]=1;
			vis[a[j-1][i]][a[j][i]]=1;
			vis2[a[j][i]]=t[j][i];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
		ans+=b[x]+b[y];
		if(a[x][y]){
			ans+=vis2[x]+vis2[y];
			cout<<ans;
		}else{
			g(x,y);
			cout<<ans;
		}
	}
	return 0;
}
