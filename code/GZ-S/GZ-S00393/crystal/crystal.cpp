//毕节梁才学校
//罗悦辉
//GZ-S00393 
#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int n;
LL m;
const int N=5e5+10;
LL a[N];
LL d[N],sd[N],sum[N];

bool check(int x,int now){
	LL t=sum[now]-sum[x]-(LL)(x-now)*sd[x];
//	cout<<t<<' '<<x<<' '<<now<<endl;
	if(t>m) return true;
	else return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1]/*,cout<<d[i]<<' '*/;
//	puts("");
	
	for(int i=n;i>=1;i--) {
		sd[i]=sd[i+1]+d[i+1];
//		printf("%d ",sd[i]);
	}
//	puts("");
	for(int i=n;i>=1;i--) {
		sum[i]=sum[i+1]+sd[i];
//		cout<<sum[i]<<' ';
	}
//	puts("");
	
	int ans=0;
	for(int i=n;i>=1;i--){
		int r=n+1,l=i+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,r-i);
	}
	printf("%d",ans);
	
	return 0;
}
