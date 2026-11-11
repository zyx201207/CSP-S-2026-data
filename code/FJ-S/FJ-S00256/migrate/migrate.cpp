#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			int k=x[i]+d,cnt=0;
			for(int j=i+1;j<=n;j++){
				if(x[j]<=k){
					cnt++;
				}
				else{
					break;
				}
			}
			if(cnt==2){
				int k1=x[i+1];
				int k2=x[i+2];
				k1+=d;k2+=d;
				unordered_map<int,bool> p;
				for(int j=i+2;j<=n;j++){
					if(x[j]<=k1){
						p[j]=1;
					}
					else{
						break;
					}
				}
				for(int j=i+3;j<=n;j++){
					if(x[j]<=k2){
						if(p[j]){
							ans++;
						}
					}
					else{
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}

