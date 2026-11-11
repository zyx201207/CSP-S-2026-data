#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	int ans=1;
	for(int i=n;i>=1;i--){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)/2;
			if(a[i]-a[mid-1]+m>=(i-mid+1)*1ll*(a[i]-a[i-1]))r=mid;
			else l=mid;
//			cout<<l<<','<<r<<'|'<<a[i]-a[mid-1]+m<<' '<<(i-mid+1)*1ll*<<endl;
		}
		ans=max(ans,i-r+1);
//		cout<<i<<'	 '<<r<<endl;
	}
	printf("%d",ans);
	return 0;
}
