#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,q;
long long w[N],a[505][505],t[505][505],k,x,y;
long long bfs(long long str,long long end){
	queue<int>qwq;
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=0;
		ans=w[x]+w[y];
		ans+=bfs(x,y);
		cout<<ans+10<<"\n";
	}
	return 0;
}
