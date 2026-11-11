#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],n,m;
bool check(long long x){
	for(long long i=1;i<=n-x+1;i++){
		long long sum=0;
		for(int j=i+1;j<i+x;j++){
			sum+=c[j]*(j-i);
			if(sum>m) break;
		}
		if((m-sum)%x==0&&m-sum>=0) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) c[i]=a[i]-a[i-1];
	long long l=1,r=n,ans=0;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
} 
