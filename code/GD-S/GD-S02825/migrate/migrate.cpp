#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,dis[N];
ll d,x[N],sum[N],cnt[N],lst[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		dis[i]=0;
		cnt[i]=1;
		lst[i]=0;
		sum[0]=1;
		for(int j=1;j<=n;j++) sum[j]=0;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d) break;
			int l=i,r=j-1;
			while(l<r){
				int mid=l+r>>1;
				if(x[j]-x[mid]<=d) r=mid;
				else l=mid+1;
			}
			dis[j]=dis[l]+1;
			cnt[j]=sum[dis[l]]-lst[l];
			lst[j]=sum[dis[j]];
			sum[dis[j]]+=cnt[j];
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
