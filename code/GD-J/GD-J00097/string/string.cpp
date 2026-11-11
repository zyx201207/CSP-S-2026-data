#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3e5+5;
ll a[maxn];
char c[maxn];
ll sum[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) ;
	int n;
	cin>>n;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll l=sum[i-1]+1,r=sum[i];
		if(l>=sum[n]/2) break;
		ll x=sum[n]-r+1,y=sum[n]-l+1;
		if(x<sum[n]/2) x=sum[n]/2;
		int p=lower_bound(sum+1,sum+n+1,x)-sum;
		int s=lower_bound(sum+1,sum+n+1,y)-sum;
		for(int j=p;j<=s;j++){
			if(c[i]!=c[j]){
				if(sum[j]<y) ans+=sum[j]-max(sum[j-1],x-1);
				else ans+=y-max(sum[j-1],x-1);
			} 
		}
	}
	cout<<ans<<"\n";
	return 0;
}

