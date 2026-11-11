#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[400000],p[400000],a[400000],n,m,cnt[400000];
void x(ll k){
	for(ll i=1;i<=m;i++)	f[i]=0;
	for(ll i=k;i<=n;i++){
		if(f[a[i]]==0){
			f[a[i]]=1;
			p[a[i]]=i;
		}else{
			for(ll j=p[a[i]];j<i;j++)	f[a[j]]=0;
			p[a[i]]=i;
			f[a[i]]=1;
		}
	}
	for(ll i=1;i<=m;i++){
		cnt[i]+=f[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		x(i);
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

