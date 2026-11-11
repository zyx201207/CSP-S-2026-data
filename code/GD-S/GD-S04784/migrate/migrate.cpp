#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=5005;
int x[N];

int dis(int l,int r){
	return abs(x[r]-x[l]);
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				if(dis(i,j)<=d) cnt++;
				for(int k1=i+1;k1<j;k1++){
					for(int k2=i+1;k2<j;k2++){
						if(k2==k1) continue;
						if(dis(i,k1)+dis(k1,j)==dis(i,k2)+dis(k2,j) && dis(i,k1)+dis(k1,j)==dis(i,j)){
							if(dis(i,k1)<=d && dis(k1,j)<=d && dis(i,k2)<=d && dis(k2,j)<=d) cnt++;
						} 
					}
				} 
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
