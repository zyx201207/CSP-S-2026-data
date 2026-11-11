#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500001],x,y,k,a[501][500001],t[501][500001];
//void dfs(ll x,ll num){
//	if(x==y){
//		minn=min(num,minn);
//		return;
//	}
//	for(int i)
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k*2;j++){
			if(j%2==0)cin>>a[i][j/2+1];
			else cin>>t[i][j/2];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
//		dfs(x,0);
		cout<<w[x];
	}
	return 0;
} //天灵灵，地灵灵，来个一等行不行！ 
