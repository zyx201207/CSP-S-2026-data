#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
long long pre[500005];
int n;
long long m;
bool c(int k){
	long long ans=0;
	for(int i=2;i<=k+1;i++){
		pre[k+1]+=d[i];
		ans+=(i-1)*d[i];
	}
	for(int i=k+2;i<=n;i++){
		pre[i]=pre[i-1]+d[i]-d[i-k];
	}
	if(m>=ans)return true;
	bool oo=0;
	for(int i=k+2;i<=n;i++){
		long long cnt=ans-pre[i-1]+k*d[i];
		ans=cnt;
		if(m>=cnt)oo=1;
	}
	return oo;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long aan=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool ok=1;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(aan>m)ok=0,aan=0;
		aan+=a[n]-a[i];
	}
	if(ok){
		m-=aan;
		if(m%n==0)cout<<n;
		else cout<<max(m%n,n-m%n);
	}
	else{
		int l=1,r=n+1,ans=1;
		while(l<r){
			int mid=(l+r)/2;
			memset(pre,0,sizeof(pre));
			if(c(mid)){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid;
			}
		}
		cout<<ans+1;
	}
} 
