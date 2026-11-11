#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char k,t;
ll f,n,m,cnt[200005];
char p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>m>>k;
		if(k!=t){
			f++;
			cnt[f]=m;
			p[f]=k;
		}else{
			cnt[f]+=m;
		}
		t=k;
	}
	ll ans=0;
	ll l=1,r=f;
	while(l<=r){
		ans+=max(cnt[l],cnt[r]);
		ll k=max(cnt[l],cnt[r]);
		if(cnt[l]>cnt[r]){
			while(k>cnt[r]){
				if(p[r]==p[l]){
					ans-=cnt[r];
				}
				k-=cnt[r];
				r--;
			}
			cnt[r]-=k;
			if(p[r]==p[l]){
				ans-=k;
			}
			l++;
			if(cnt[r]==0){
				r--;
			}
		}else{
			while(k>cnt[l]){
				if(p[r]==p[l]){
					ans-=cnt[l];
				}
				k-=cnt[l];
				l++;
			}
			cnt[l]-=k;
			if(p[r]==p[l]){
				ans-=k;
			}
			r--;
			if(cnt[l]==0){
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
