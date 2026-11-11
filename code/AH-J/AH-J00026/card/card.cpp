#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x;
bool f[500010];
ll pos[300010],cnt[300010],a[500010],b[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}	
	ll t=0;
	for(ll k=1;k<=n;k++){
		memset(f,0,sizeof f);
		memset(pos,0,sizeof pos);
		++t;
		for(ll i=t;i<=n;i++){
			if(!f[a[i]]){
				f[a[i]]=1;
				pos[a[i]]=i;
			}
			if(f[a[i]]){
				for(ll j=pos[a[i]];j<=i;j++){
					f[a[j]]=0;
				}	
				f[a[i]]=1;
				pos[a[i]]=i;
			}		
		}	
		for(ll i=1;i<=m;i++){
			if(f[i]) cnt[i]++;
		}	
		for(ll i=1;i<=n;i++){
			a[i]=b[i];
		}	
	}	
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}	
	return 0;
} 
