#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2*1e6+10;
int c,t;
LL island[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		LL n,d,ans=0;
		cin>>n>>d;
		memset(island,0,sizeof(island));
		for(LL i=1;i<=n;i++){
			cin>>island[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				LL cntFly=(island[j]-island[i]+d-1)/d;
				if(cntFly!=1 && (island[j]-island[i])%d!=0 && j-i-1==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
