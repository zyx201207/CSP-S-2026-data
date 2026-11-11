#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=500010;
int n,p,ans;
LL m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,mid;
		while(l<r){
			mid=(l+r)/2;
			LL sum=1ll*(i-mid)*a[i]-(s[i]-s[mid]);
			if(sum<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	printf("%d\n",ans);
	return 0;
} 
