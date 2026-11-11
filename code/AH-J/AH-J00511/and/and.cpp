#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2*1e5+10;
ll AAA[30+10]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
ll a[N],n,m,maxn=-1,vis[N];
void dfs(ll choice,ll ans){
	if(choice==0){
		maxn=max(maxn,ans);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(ans==0){
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				dfs(choice-1,a[i]);
				vis[a[i]]=0;
			}
		}else{
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				dfs(choice-1,ans&a[i]);
				vis[a[i]]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll f=0,mmmaxn=-1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mmmaxn=max(mmmaxn,a[i]);
		for(ll j=0;j<30;j++){
			if(AAA[j]==a[i]) f++;
		}
	}
	if(f==n){
		sort(a+1,a+n+1);
		ll l=n;
		m--;
		while(m--){
			a[n]=(a[n]&a[--l]);
		}
		cout<<a[n];
		return 0;
	}
	if(m==1){
		cout<<mmmaxn;
		return 0;
	}
	if(m==n){
		ll ans7=a[1];
		for(ll i=2;i<=n;i++){
			ans7&=a[i];
		}
		cout<<ans7;
		return 0;
	}
	if(m==2){
		ll maxn8=-1;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxn8=max(maxn8,(a[i]&a[j]));
			}
		}
		cout<<maxn8;
		return 0;
	}
	if(m==n-1){
		ll sum1112=a[1],maxn1112=-1;
		for(ll i=2;i<=n;i++){
			sum1112&=a[i];
		}
		for(ll i=1;i<=n;i++){
			ll tmp=sum1112;
			maxn1112=max(maxn1112,tmp^a[i]);
		}
		cout<<maxn1112;
		return 0;
	}
	dfs(m,0);
	cout<<maxn;
	return 0;
}
