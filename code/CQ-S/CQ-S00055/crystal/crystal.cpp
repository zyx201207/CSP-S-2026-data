#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans;
long long m,a[500005],sum;
bool check(int mid){
	long long cnt=0;
	for(int i=mid;i>=1;i--){
		cnt+=a[mid]-a[i];
		if(cnt>m){
			y=i+1;
			cnt-=a[i]-a[y];
			ans=max(ans,mid-i);
			return 1;
		}
		if(i==1)ans=mid;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			x=mid;
		}else r=mid-1;
	}
	for(int i=x;i>=y-1;i--){
		sum+=a[x]-a[i];
		if(sum>m){
			sum-=a[i]-a[l];
			break;
		}
	}
	for(int i=x+1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m)sum-=a[i]-a[++l];
		ans=max(i-l+1,ans);
	}
	printf("%d",ans);
	return 0;
}
