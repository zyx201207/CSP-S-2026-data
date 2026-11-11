#include<bits/stdc++.h>
using namespace std;
#define int long long
//luogu id afewdgre
int c,t,n,d,x[2000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++){
				int num=0,las=i,flag=0;
				for(int j=i+1;j<=n;j++){
					if(num+x[j]-x[j-1]>d){
						if(x[j]-x[j-1]>d) break;
						else num=x[j]-x[j-1],las=j-1;
					}
					else num+=x[j]-x[j-1];
					if(las!=i&&num+x[las]-x[las-1]<=d){
						if(x[las]+x){
							flag=0;
							break;
						}else{
							if(num+x[las]-x[las-2]>d) flag=1;
						}
					}
					ans+=flag;
					//cout<<i<<' '<<j<<' '<<ans<<'\n';
				}
			}
			cout<<ans<<'\n';
		}
	}else{
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			int p=x[2]-x[1];
			if(d/p<=1) cout<<0<<'\n'; 
			else{
				cout<<max(0ll,n-(d/p)*2+1)<<'\n';
			}
		}
	}
}
