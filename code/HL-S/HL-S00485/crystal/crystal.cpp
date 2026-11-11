#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
typedef long long ll;
ll n,m,a[N],sum,ans,r,k[N],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	r=n;cnt=n;
	for(int i=n;i>=1;i--){
		sum+=a[r]-a[i];
		if(a[i]==a[i-1]){
			k[cnt]++;
		}
		else{
			k[cnt]++;
			cnt=i-1;
		}
		if(sum<=m) ans=max(ans,r-i+1);
		else{
			while(sum>m){
				ll x=r-k[r]-i+1;
			    ll y=x*(a[r]-a[r-k[r]]);
			    sum-=y;
			    r=r-k[r];
			}			
		}
	}
	cout<<ans;
	return 0;
} 