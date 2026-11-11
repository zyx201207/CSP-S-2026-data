#include<bits/stdc++.h>
using namespace std;
int w[10010],k[10010];
int a[1001][1001],t[1001][1001];
int c,n,m,d,q;
int f(int x){
	for(int i=1;i<=n;i++){
		bool f=false;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x) f=true;
		}
		if(!f) return 0;
	}
	return 1;
}
int g(int x,int y){
	for(int i=1;i<=n;i++){
		bool f1=false,f2=false;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x) f1=true;
			if(a[i][j]==y) f2=true;
		}
		if(f1&&f2) return 1;
		f1=false;
		f2=false;
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int Q=0;Q<q;Q++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=w[x]+w[y];
		if(g(x,y)){
			ans+=t[x][x]+t[x][y];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=m;i++){
			if(f(i)){
				ans+=t[x][x]+t[x][i]+t[i][y];
				break;
			}
		}
		cout<<ans<<endl;
	}
}