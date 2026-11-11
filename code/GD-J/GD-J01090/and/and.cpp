#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=2e5+10;
ll n,m,ans,a[N],p[N],s[N];
void dfs(int idx,int cur,ll tot){
	if(idx>n+1){
		return;
	}
	if(cur==m){
		ans=max(ans,tot);
		return;
	}
	dfs(idx+1,cur,tot);
	dfs(idx+1,cur+1,tot&a[idx]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool fl=1;
	ll mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll k=log2(a[i]+1);
		if((1<<k)-1!=a[i])fl=0;
		mx=max(a[i],mx);
	}
	if(n<=20){
		dfs(1,0,(1ll<<32)-1);
		cout<<ans;
		return 0;
	}
	if(fl){
		sort(a+1,a+1+n,greater<ll>());
		cout<<a[m];
		return 0;
	}
	if(m==1){
		ll mxs=0;
		for(int i=1;i<=n;i++)mxs=max(mxs,a[i]);
		cout<<mxs;
		return 0;
	}
	if(m==2){
		ll mxs=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mxs=max(mxs,a[i]&a[j]);
			}
		}
		cout<<mxs;
		return 0;
	}
	if(m==n){
		ans=(1ll<<32)-1;
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		p[0]=(1ll<<32)-1;
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]&a[i];
		}
		s[n+1]=(1ll<<32)-1;
		for(int i=n;i>=1;i--){
			s[i]=s[i+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,p[i-1]&s[i+1]);
		}
		cout<<ans;
		return 0;
	}
	if(mx<4){
		map<int,int>mp;
		for(int i=1;i<=n;i++)mp[a[i]]++;
		if(mp[3]>=m){
			cout<<3;
			return 0;
		}
		if(mp[2]>=m){
			cout<<2;
			return 0;
		}
		if(mp[3]+mp[2]>=m){
			cout<<2;
			return 0;
		}
		if(mp[1]>=m){
			cout<<1;
			return 0;
		}
		if(mp[3]+mp[1]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
}
