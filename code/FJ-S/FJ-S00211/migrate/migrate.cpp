#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st stack
#define qu queue
#define qp priority_queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 100000
ll c=0,t=0,n=0,d=0;
ll a[N]={0};
ll dfs(ll sum,ll x,ll y){
	if(sum==0&&x==y){
		return 1;
	}
	if(sum==0&&x!=y){
		return 0;
	}
	ll b=d;
	ll c=0;
	while(1){
		if(a[x+c+1]-a[x+c]<=b&&x+c+1<=n){
			c++;
			b-=a[x+c+1]-a[x+c];
		}else{
			break;
		}
	}
	ll ans=0;
	for(ll i=x;i<=x+c;i++){
		ans+=dfs(sum-1,i,y);
	}
	return ans;
}
int main(){
	qwq;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){//µº1 
			for(ll j=1;j<=n;j++){//µº2 
				ll sum=0;//ÖÁÉÙ·Ésum´Î 
				for(ll k=i;k<=j;){
					ll b=1,c=d;
					if(a[k]-a[k-1]>d){
						break;
					}
					while(1){
						if(a[k]-a[k-1]<=c&&k<=j){
							k++;
							c-=a[k]-a[k-1];
						}else{
							break;
						}
					}
					sum++;
				}
				if(dfs(sum,i,j)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
