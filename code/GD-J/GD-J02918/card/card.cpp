#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005],ans[500005],now[500005],pd;
void work(ll l,ll r){
	ll le=0;
	for(ll i=l;i<=r;i++){
		ll x=a[i],p=0,k=0;
		for(ll j=1;j<=le;j++){
			if(now[j]==x){
				p=1;
				k=j;
				break;
			}
		}
		if(p==0){
			le++;
			now[le]=x;
		}else	le=k;
	}
	for(ll i=1;i<=le;i++)	ans[now[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(ll i=1;i<=n;i++){
		if(a[i]!=b[i]){
			pd=1;
			break;
		}
	}
	if(pd==0){
		for(ll i=1;i<=n;i++){
			if(a[i]!=a[i+1])	ans[a[i]]=i;
		}
		for(ll i=1;i<=m;i++)	cout<<ans[i]<<" ";
		return 0;
	}
	for(ll i=1;i<=n;i++)	work(i,n);
	for(ll i=1;i<=m;i++)	cout<<ans[i]<<" ";
	return 0;
}
