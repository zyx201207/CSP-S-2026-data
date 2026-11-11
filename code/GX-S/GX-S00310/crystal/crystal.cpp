#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
long long ma=LONG_MIN;
long long rf(int R){
	long long l=1,r=R,ans=LONG_MAX;
	while(l<=r){
		long long mid=l+((r-l)>>1);
		if((R-1-mid+1)*a[R]-(sum[R-1]-sum[mid-1])==m){
			return mid;
		}
		if((R-1-mid+1)*a[R]-(sum[R-1]-sum[mid-1])<m){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long cnt=0,b;
		for(int j=i;i>=1;j--){
			if(a[j]==a[i]){
				cnt++;
			}else{
				b=j+1;
				break;
			}
		}
		cnt+=b-rf(b);
		ma=max(cnt,ma);
	}
	cout<<ma;
	return 0;
}
