#include<bits/stdc++.h>
using namespace std;
#define int long long
struct op{
	int pts;
	int step;
};
int x[2000002],vis[2000002],ccb[2000002];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		for(int sc=1;sc<=t;sc++){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			int rate=d/(x[2]-x[1]);
			if(rate<2){
				cout<<0<<endl;
				continue;
			}
			cout<<max(n-2*rate+1,0LL)<<endl;
		}
	}else{
	for(int sc=1;sc<=t;sc++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		queue<op>nb;
		int ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i;j<=n;j++){
				vis[j]=2000500;
				ccb[j]=0;}
			nb.push({i,0});
			while(!nb.empty()){
				op g2=nb.front();
				int g1=g2.pts+1,con=x[g2.pts]+d;
				if(vis[g2.pts]>g2.step){
					vis[g2.pts]=g2.step;
					ccb[g2.pts]=1;
				}else if(vis[g2.pts]==g2.step)ccb[g2.pts]++;
				while(x[g1]<=con&&g1<=n){
					nb.push({g1,g2.step+1});
					g1++;
				}
				nb.pop();
			}for(int j=i;j<=n;j++){
				ans+=(ccb[j]==2);
			}
		}cout<<ans<<'\n';
	}	
	}
	return 0;
}
