#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int a[500005],sum[500005];
int f(int k){
	int l=1,r=k,mid=(k)/2;
	while(mid){
		if(a[k]*(k-l)-(sum[k-1]-sum[l-1])>m){
			l+=mid;
		}else{
			if(l==1) return k;
			else l=max(l-mid,1ll);
		}mid/=2;
	}if(a[k]*(k-l)-(sum[k-1]-sum[l-1])>m){
		l+=1;
	}return r-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		ans=max(ans,f(i));
	}cout << ans << ' ';
	return 0;
}
