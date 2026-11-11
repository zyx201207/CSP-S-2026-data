#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010];
ll dist[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll ma=0;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		memset(dist+1,0,n+1);
		for(ll j=1;j<=n;j++){
			dist[j]=i-a[j];
//			cout<<a[j]<<' '<<dist[j]<<' '<<i<<endl;
		}
		sort(dist+1,dist+1+n);
//		for(ll j=1;j<=n;j++){
//			cout<<a[j]<<' '<<dist[j]<<' '<<i<<endl;
//		}
		ll sta=1;
		for(ll j=1;j<=n;j++){
			if(dist[j]>=0){
				sta=j;
				break;
			}
		}
//		cout<<endl<<sta<<endl<<endl;
		ll cnt=0;
		for(ll mm=m,now=sta;mm>0&&now<=n;mm--){
//			cout<<"IN";
//			cout<<now<<' '<<a[now]<<' '<<dist[now]<<' '<<i<<endl;
			if(dist[now]==0){
				now++;
				mm++;
//				cout<<now<<' '<<a[now]<<' '<<i<<endl;
			}
			else{
				dist[now]--;
//				cout<<now<<' '<<a[now]<<' '<<dist[now]<<' '<<i<<endl;
			}
		}
		for(ll j=sta;j<=n;j++){
			if(dist[j]==0)cnt++;
		}
		ma=max(ma,cnt);
	}
	cout<<ma;
	return 0;
}
