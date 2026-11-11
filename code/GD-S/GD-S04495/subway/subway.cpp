#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e6+10;

ll c,n,m,d,q,w[N],k[N],a[3000][3000],t[3000][3000],ans,x,y,cnt,tr; 

//void dfs(int u){
//	
//	if(cnt>20){
//		cnt--;
//		return;
//	}
//	if(u==y){
//		ans=min(ans,cnt);
//	}
//	for(int i=1;i<=k[u];i++){
//		ans+=t[u][k[u]];
//		cnt++;
//		dfs(k[u]);
//		cnt--;
//		ans-=t[u][k[u]];
//	}
//	for(int i=1;i<=n;i++){
//		if(i!=tr){
//			for(int j=1;j<=k[i];j++){
//				if(a[j]==u){
//					ans+=t[u][]
//				}
//			}
//		}
//	}
//}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>m;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		if(x==y){
			cout<<w[x]+w[y]<<"\n";
		}
//		dfs(x);
	}
	return 0;
}
