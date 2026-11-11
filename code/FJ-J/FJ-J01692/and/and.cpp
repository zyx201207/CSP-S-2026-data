#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2*100000+10]; 
bool cmp(const ll &x,const ll &y){
	return x>y;
}
ll cnt[5]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,maxn=-1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=4)cnt[a[i]]++;
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(n==m){
		maxn=a[1];
		for(ll i=2;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}
	else if(m==1)cout<<a[1];
	else if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=1+1;j<=n;j++){
				if(i==j)continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	else if(maxn<=4){
		if(cnt[4]>=m)cout<<4;
		else if(cnt[3]>=m)cout<<3;
		else if(cnt[2]>=m)cout<<2;
		else if(cnt[1]>=m)cout<<1;
		else{
			if(cnt[3]+cnt[2]>=m)cout<<2;
			else if(cnt[2]+cnt[1]>=m)cout<<1;
			else cout<<0;
		}
	}
	else {
		maxn=a[1];
		for(ll i=2;i<=m;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}
	return 0;
}
