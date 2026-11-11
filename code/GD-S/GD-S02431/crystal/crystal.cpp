#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;

int n,ans=0;
ll m,a[N],sum[N];

bool check(int i,int mid){
	ll res=1ll*(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
	return res<=m;
}

int main(){
	//freopen("crystal4_1.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,pos=i;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(i,mid)){
				r=mid-1;
				pos=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}	
	printf("%d",ans);
}
