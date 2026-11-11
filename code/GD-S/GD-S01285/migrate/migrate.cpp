#include<bits/stdc++.h>
using namespace std;
#define int long long 

struct node{
	int dist,num;
};
const int maxn=5005,INF=1e9+5;
int x[maxn],c,t,n,d;
node f[maxn][maxn];

inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>x[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			f[i][j].dist=INF,f[i][j].num =0;
			if(abs(x[i]-x[j])<=d) f[i][j].dist =1,f[i][j].num =1;
 		}
		f[i][i].dist =0,f[i][i].num =1;
	} 
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=i+1;k<=j-1;++k){
				if(f[i][k].num >0&&f[k][j].num >0){
				if(f[i][k].dist +f[k][j].dist <f[i][j].dist ){  
					//cout<<"i "<<i<<" j "<<j<<" k "<<k<<'\n';
					//cout<<"f[i][k].dist "<<f[i][k].dist<<" f[k][j].dist "<<f[k][j].dist<<" f[i][j].dist "<<f[i][j].dist<<'\n';
					//cout<<"f[i][k].num "<<f[i][k].num<<" f[k][j].num "<<f[k][j].dist<<" f[i][j].num "<<f[i][j].num<<'\n';
					f[i][j].dist =f[i][k].dist +f[k][j].dist;
					f[i][j].num =f[i][k].num *f[k][j].num;
				}else if(f[i][k].dist +f[k][j].dist ==f[i][j].dist ){
					f[i][j].num +=1;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			//cout<<"i = "<<i<<" j = "<<j<<" "<<f[i][j].dist <<" "<<f[i][j]. num<<'\n';    
			if(f[i][j].num ==2) ans++;
		}
	}
	cout<<ans<<'\n'; 
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--) solve();
	return 0; 
}

