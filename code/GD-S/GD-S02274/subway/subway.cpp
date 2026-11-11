#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=500+10;
int dp[N][N],w[N],r[N],k[N],a[N][N],t[N][N],x[N],y[N];//dp[i]表示在地i次操作上，最多用dp[i] 可合成
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2 
struct node{
	int na,sum,fr;
};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,c,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]];
//		queue<node>q;
//		q.push({x[i],ans,0});
//		while(!q.empty()){
//			node crt=q.front();q.pop();
//			cout<<crt.na<<' '<<crt.sum<<' '<<crt.fr<<endl; 
//			if(crt.na==y[i]){
//				ans=crt.sum;
//				break;
//			}
//			for(int z=1;z<=m;z++){
//				for(int j=1;j<=k[z];j++){
//					if(a[z][j]==crt.na){
//					for(int s=1;s<=k[z];s++){
//						if(a[z][s]!=crt.na){
//							
//							if(crt.fr!=z){
//								if(crt.fr==0){
//									q.push({a[z][s],crt.sum+t[z][s],z});
//								}
//								for(int op=1;op<=k[crt.fr];op++){
//									if(a[crt.fr][op]==a[z][s])q.push({a[z][s],crt.sum+t[crt.fr][op]+t[z][s],z});	
//								}
//								
//							}else{
//								q.push({a[z][s],crt.sum,z});
//							}
//							
//						}
//						
//					}break;				
//					}	
//	
//				}	
//			}	
//				
//		}
		cout<<ans<<endl;
	}
	return 0;
}
