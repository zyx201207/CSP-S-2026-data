#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],pre[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=-1,r=i,mid;
		while(l+1<r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid)-(pre[i]-pre[mid])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r);
	}
	cout<<ans<<endl;
}
