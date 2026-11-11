#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
const int BJ=5e7;
int n,m,ans,big,a[N];
int befind(int x){
	int ans=-1,l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]>x) r=mid-1;
		else{
			ans=mid;
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		big=max(big,abs(a[i]));
	}
	sort(a+1,a+n+1);
	if(a[n]-a[n-1]==a[n-1]-a[n-2]){
		for(int i=n;i>=1;i--){
			m-=(n-i)*(a[n]-a[n-1]);
			if(m<0) break;
			ans++;
		}
		printf("%lld",ans);
	}else {
		for(int i=-big;i<=big;i++){
			int wz=befind(i);
			if(wz==-1)continue;
			int cs=m,cnt=0;
			for(int j=wz;j>0;j--){
				if(cs<i-a[j]) break;
				cnt++,cs-=(i-a[j]);
			}
			ans=max(ans,cnt);
		}
		printf("%lld",ans);
	}
	return 0;
}
