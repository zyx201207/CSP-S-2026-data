#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans,g,mj;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		if(c==0||c==11||c==12){
			g=x[2]-x[1];
			mj=d/g;
			if(mj<=1){
				cout<<0<<"\n";
				continue;
			}
			for(int i=mj+1;i<=n;++i){
				if(i%mj!=0){
					if((i/mj+1)==2&&mj-1==1) ans+=n-i;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
