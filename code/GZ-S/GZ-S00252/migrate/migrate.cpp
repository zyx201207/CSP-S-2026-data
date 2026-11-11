//¿ÓºŒ‘∆ GZ-S00252 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second 
#define pb push_back
#define pq priority_queue
const int N=2E6+10;
ll c,T,n,d,x[N],ans,t[N],cnt,vis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			vis[i]=0;
		}
		for(ll i=1;i<=n;i++){
			cnt=0;
			for(ll j=i+1;j<=n;j++){
				cnt+=abs(x[j]-x[j-1]);
				if(cnt>d){
					t[i]=j-1;
					break;
				}
				if(j==n){
					t[i]=n;
				}
			}
			if(t[i]==i&&i!=n){
				vis[i]=1;
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=t[i]+1;j<=n;j++){
				cnt=0;
				for(ll k=i+1;k<=j-2;k++){
					if(t[k-1]>=k+1&&(t[k]>=t[k+1]&&(!vis[t[k]]||t[k]>=j))){
						cnt++;
						if(cnt==2){
							break;
						}
					}
				}
				ans+=(cnt==1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
