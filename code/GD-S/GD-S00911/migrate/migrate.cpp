#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[1000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				queue<int>x,y;
				int mi=1e18,lx=0;
				x.push(i);y.push(0);
				while(x.size()){
					int xx=x.front(),yy=y.front();
					x.pop();y.pop();
					if(xx==j&&yy<=mi)mi=yy,lx++;
					if(yy>mi)continue;
					for(int k=xx+1;k<=j;k++){
						if(a[k]-a[xx]<=m)x.push(k),y.push(yy+1);
					}
				}
				if(lx==2)ans++;
			}
		}
		cout<<ans<<'\n';
	} 
}
