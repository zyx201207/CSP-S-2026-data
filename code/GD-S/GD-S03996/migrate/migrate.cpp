#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t;
ll x[20005];
ll mp[5005][5005];
ll num[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=1e18;
				num[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d)break;
				mp[j][i]=1;
				num[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i>=k||k>=j)continue;
					if(mp[i][j]>mp[i][k]+mp[k][j]){
						mp[i][j]=mp[i][k]+mp[k][j];
						num[i][j]=num[i][k]*num[k][j];
					}else if(mp[i][j]==mp[i][k]+mp[k][j]){
						num[i][j]+=num[i][k]*num[k][j];
					}
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(num[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
} 
