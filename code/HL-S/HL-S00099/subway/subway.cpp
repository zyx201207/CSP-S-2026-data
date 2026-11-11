#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int c,n,m,d,q;
int w[N];
int k[505],a[1010],t[1010];
int ans=0;
int dfs1(int u){
	ans+=min(t[u],t[u+1]);
	if (u==1) return ans;
	else dfs1(u-1);
}
int dfs2(int x,int y){
	ans+=w[x]+w[y];
	ans+=min(dfs1(x),dfs1(y));
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for (int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		cout<<dfs2(x,y)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
