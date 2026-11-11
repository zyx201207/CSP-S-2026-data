#include<bits/stdc++.h>
#define int long long
struct node{
	int id,dis;
}a[510][100010];
int c,n,m,d,q,ans;
int w[1000010];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) std::cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		std::cin>>k;
		for(int j=1;j<=k;j++){
			std::cin>>a[i][j].id>>a[i][j].dis;
		}
	}
	while(q--){
		int x,y;
		ans=INT_MAX;
		std::cin>>x>>y;
		std::cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}//It's too late to apologize.
