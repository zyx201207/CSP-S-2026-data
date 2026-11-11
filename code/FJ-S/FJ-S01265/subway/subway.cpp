#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,arr[500001],p[2][1000001],vis[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		cin>>p[i][0];
		for(int j=1;j<=p[i][0];j++) cin>>p[i][j];
	}
	while(q--){
		int l,r,ans=0,cnt=1e9;
		memset(vis,0,sizeof(vis));
		cin>>l>>r;
		ans+=arr[l]+arr[r];
		for(int j=1;j<=p[1][0];j++) vis[p[1][j]]=1;
		for(int j=1;j<=p[2][0];j++){
			if(vis[p[2][j]]==1) cnt=min(cnt,p[2][j+p[2][0]]+p[1][j+p[1][0]]);
		}
		cout<<ans+cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
