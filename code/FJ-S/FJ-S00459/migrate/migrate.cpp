#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,dp[N],mx;
ll d,a[N],f[N],ans,tr[N];
vector<int> v[N];
int lowbit(int x){
	return x&-x;
}
void update(int x,ll val){
	while(x<=mx){
		tr[x]+=val;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll sum=0LL;
	while(x){
		sum+=tr[x];
		x-=lowbit(x);
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0LL;
		for(int i=1;i<n;i++){
			dp[i]=0;
			for(int j=i+1;j<=n;j++){
				f[j]=0LL;
				dp[j]=N;
				v[j].clear();
			}
			f[i]=1LL;
			mx=0;
			for(int j=i+1;j<=n;j++){
				int l=i,r=j-1,mid,pos=j;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[j]-a[mid]<=d){
						pos=mid;
						r=mid-1;
					}else l=mid+1;
				}
				if(pos<j&&dp[pos]<N){
					dp[j]=dp[pos]+1;
					mx=max(mx,dp[j]);
				}
			}
			for(int j=i;j<=n;j++){
				if(dp[j]>=N) continue;
				int l=i+1,r=n,mid,pos=n+1;
				while(l<=r){
					mid=(l+r)>>1;
					if(a[mid]-a[j]>d){
						pos=mid;
						r=mid-1;
					}else l=mid+1;
				}
				if(pos<=n) v[pos].push_back(j);
			}
			for(int j=1;j<=mx;j++) tr[j]=0;
			update(1,1LL);
			for(int j=i+1;j<=n;j++){
				int siz=v[j].size();
				for(int k=0;k<siz;k++) update(dp[v[j][k]]+1,-f[v[j][k]]);
				if(dp[j]>=N) continue;
				f[j]=query(dp[j]);
				if(f[j]==2LL) ans++;
				if(dp[j]<mx) update(dp[j]+1,f[j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
