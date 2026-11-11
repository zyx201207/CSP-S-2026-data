#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],ans;
pair<__int128,__int128> e[314][314];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;++i) cin>>x[i];
			ans=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					e[i][j].first=0x3f3f3f3f3f3f3f3f;
					e[i][j].second=0;
				}
				e[i][i].first=0;
			}
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n&&x[j]-x[i]<=d;++j) e[i][j]=e[j][i]=make_pair(1,1);
			}
			for(int k=1;k<=n;++k){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=n;++j){
						if(k!=i&&k!=j&&i!=j){
							if(e[i][j].first==e[i][k].first+e[k][j].first) e[i][j].second+=min(e[i][k].second*e[k][j].second,(__int128)3);
							else if(e[i][j].first>e[i][k].first+e[k][j].first) e[i][j]=make_pair(e[i][k].first+e[k][j].first,min(e[i][k].second*e[k][j].second,(__int128)3));
						}
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(e[i][j].second==2){
						//cout<<i<<' '<<j<<'\n';
						++ans;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	if(c<=12&&c>=11){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>x[i];
			}
			long long D=x[2]-x[1];
			if(2*D>d){
				cout<<"0\n";
				continue;
			}
			long long gp=d/D*2;
			cout<<n-gp+1<<'\n';
		}
	}
	return 0;
}
