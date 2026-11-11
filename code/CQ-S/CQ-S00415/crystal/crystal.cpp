#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],b[1000010],ans;
bool ok(int l,int r){
	return a[r]*(r-l+1)-(b[r]-b[l-1])<=m;
}
signed main(){
//	freopen("crystal1.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n+1;
		for(;l+1<r;){
			int mid=(l+r)/2;
			if(ok(i,mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
}
