#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],dp[N],sum[N],ans,cnt1,tmp,c[N],b[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=a[i];
		c[i]=a[i];
	}sort(b+1,b+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+b[i];
		dp[i]=b[i]*i-sum[i];
		if(dp[i]>m){
			cnt1=i-1;
			break;
		}
	}
	sort(c+1,c+n+1);
	bool flag=false;
	for(ll i=1; i<=n; i++) {
		if(c[i]==c[i+1]) {
			tmp++;
			flag=true;
			if(i+1==n) {
				tmp++;
				ans=max(tmp,ans);
			}
		} else if(flag==true) {
			flag=false;
			ans=max(tmp,ans);
			tmp=0;
		}
	}
	cout<<max(cnt1,ans);
	return 0;
}
