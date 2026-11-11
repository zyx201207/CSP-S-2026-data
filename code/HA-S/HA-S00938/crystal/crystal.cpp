#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005]={0},f[500005]={0},g[500005]={0};
long long pd(long long l,long long r,long long i){
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(g[mid]>=i){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int lt=1;
	for(int i=1;i<=n;i++){
		g[i]=g[i-1]+(a[i]-a[i-1])*(i-lt);
		if(g[i]<=m){
			f[i]=f[i-1]+1;
		}else{
			long long j=pd(lt,i-1,g[i]-m);
			f[i]=f[i-1]-f[j]+1;
			g[i]=g[i]-g[j]-((a[i]-a[j])*(j-lt+1));
			lt=j+1;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
