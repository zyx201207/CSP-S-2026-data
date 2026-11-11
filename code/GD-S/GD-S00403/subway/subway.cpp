#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d,xx,yy,ans;
int a[500050],w[500050],k[500050],b[500050];
int dfs(int x,int y){
	for(int i=1;i<=n;i++){
		ans+=k[i];
		for(int j=1;j<=w[i];j++){
			x=a[j];
			ans+=b[j];
			if(x==y){
				return ans;
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
		for(int j=1;j<=w[i];j++){
			cin>>a[j]>>b[j];
		}
	}
	while(q--){
		cin>>xx>>yy;
		cout<<dfs(xx,yy)<<endl;
	}
	return 0;
}
