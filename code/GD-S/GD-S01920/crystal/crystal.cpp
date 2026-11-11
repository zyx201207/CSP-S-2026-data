#include<bits/stdc++.h>
#define int ll
using namespace std;
using ll=long long;
const int M=5e5+5;
ll n,m,ans,a[M];
ll cnt[M],sum[M],num[M];
bool A=1,B=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
		if(a[i]>=2&&a[i]!=a[i-1]+1)B=0;
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				int nm=min(a[i]?max(0ll,(sum[i]-sum[j-1]+m)/a[i]):i-j+1,i-j+1);
				ans=max({ans,nm});
			}
		}
	}else if(!A&&!B){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			cnt[i]=cnt[i-1];
			if(a[i]<0)cnt[i]++,num[i]+=a[i];
		}
		for(int i=1;i<=n;i++){
			int nm=min(a[i]?max(0ll,(sum[i]+m)/a[i]):i,i);
			int mn=min(a[i]?max(0ll,(sum[i]+m-num[i])/a[i]):cnt[i],cnt[i]);
			ans=max({ans,nm,mn});
		}
		cout<<ans;
	}else if(A){
		cout<<min(m+1,n);
	}else if(B){
		int cha=a[2]-a[1];
		cout<<min(m/cha+1,n);
	}
	
	
	return 0;
}
