#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=2000010;
typedef long long ll;
ll n,d;
ll a[N];
int dis[N],cnt[N];
ll f[N],g[N];
int get(ll l,ll r){
	int c=0;
	for(int i=1;i<=n;i++) if(a[i]>=l && a[i]<=r) c+=g[i]+1;
	return c;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int _=1;_<=t;_++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],f[i]=0;
		ll ans=0;
		int p=n;
//		for(int i=n;i>=1;i--){
//			while(p>i && a[p]-a[i]>d) p--;
//			if(p>i){
//				if(p>i+1){
//					f[i]+=get(a[p-2]+d+1,a[p-1]+d);
//				}
//				else f[i]=f[p];
//				g[i]=p-i+g[p];
//			}
//			cout<<p<<" "<<i<<" "<<f[i]<<endl;
//			ans+=f[i];
//		}
//		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			dis[i]=0,cnt[i]=1;
			int p=i;
			for(int j=i+1;j<=n;j++){
				while(p<j && a[j]-a[p]>d) p++;
				if(p==j) break;
				cnt[j]=0;
				for(int k=p;k<=p+3 && k<j;k++) if(dis[k]==dis[p]) cnt[j]+=cnt[k];
				dis[j]=dis[p]+1; 
				if(cnt[j]==2) ans++;
//				cout<<cnt[j]<<" ";
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

