#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e6+5;
const ll inf=maxn*5;
ll c,T,n,d,x[maxn];
ll dis[maxn],way[maxn];
void solve(){
	cin >>n>>d;
	for(ll i=1;i<=n;i++) cin >>x[i];
	if(n==1){
		cout <<0<<"\n";
		return ;
	}
	ll ddd=x[2]-x[1],flag=0;
	for(ll i=2;i<n;i++) if(x[i+1]-x[i]!=ddd) flag=1;
	if(flag==0&&n>300){
		ll res=(d+ddd-1)/ddd;
		if(res==1){
			cout <<0<<"\n";
			return ;
		}
		ll len=2*res-2,ans=0;
		for(ll p=len;p<=n;p++){
			ans+=p-len+1;
		}
		cout <<ans<<"\n";
		return ;
	}
	int kz=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d) kz=i;
	} 
	if(kz!=0&&n>300){
		if(kz==n){
			cout <<0<<"\n";
			return ;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x[kz+1]-x[i]>d){
				ans++;
			}
		}
		cout <<ans<<"\n";
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++) dis[j]=inf,way[j]=0;
		dis[i]=0,way[i]=1;
		for(ll j=i+1;j<=n;j++){
			for(ll last=j-1;last>=i;last--){
				if(x[j]-x[last]>d) break;
				ll now=dis[last]+1;
				if(now<dis[j]){
					dis[j]=now;
					way[j]=way[last];
				}
				else if(now==dis[j]) way[j]+=way[last];
			}
			if(way[j]==2) ans++;
		}
	}
	cout <<ans<<"\n";
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >>c>>T;
	while(T--) solve();
	return 0;
}
