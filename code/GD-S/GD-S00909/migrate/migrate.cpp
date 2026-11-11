#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10;
ll C,t,n,d,x[N],cnt[N],st[N],sum[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--){
		cin>>n>>d; ll ans=0;
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++){
			memset(cnt,0,sizeof cnt); memset(st,0,sizeof st); memset(sum,0,sizeof sum);
			ll k=i,l=i; cnt[0]++; sum[i]++;
			for(ll j=i+1;j<=n;j++){
				while(x[j]-x[k]>d){
					cnt[st[k]]--; k++;
				}
				if(k==j) break;
				st[j]=st[k]+1;
				if(st[j]!=st[j-1]) l=j-1;
				cnt[st[j]]++;
				sum[j]=sum[j-1]+cnt[st[k]];
				if(sum[l]-sum[k-1]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

