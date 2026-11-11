#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const ll inf=1ll<<60;
ll c,T,n,d,x[N],dis[N],ans,cnt[N],sum[N],up2[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	x[0]=-inf,x[n+1]=inf;
	for(int i=1;i<n;i++){
		int p=i,l=p,r=p;
		for(int j=1;j<=n;j++){
			dis[j]=inf;
			cnt[j]=sum[j]=up2[j]=0;	
		}
		dis[p]=up2[p]=0;
		cnt[p]=sum[p]=1;
		for(int j=i+1;j<=n;j++){
			while(l<j&&x[l]+d<x[j]) l++;
			if(l==j) break;
			while(r+1<j&&dis[r+1]==dis[l]) r++;
			bool dayu2=0;
			if((up2[r]-up2[l-1]>=1)||(sum[r]-sum[l-1]>2)) dayu2=1;
			if(dayu2){
				up2[j]=up2[j-1]+1;
				cnt[j]=0;
			}else{
				cnt[j]=sum[r]-sum[l-1];
			}
			sum[j]=sum[j-1]+cnt[j];
			dis[j]=dis[r]+1;
			if(cnt[j]==2&&!dayu2)
				ans++;
		}
	}
	cout<<ans<<'\n';
	ans=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}