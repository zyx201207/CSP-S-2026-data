#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500010;

int n,ans;
ll a[N],m,b[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];

	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r-1){
			int mid=(l+r)>>1;
			if((a[i]*(i-mid+1))-(b[i]-b[mid-1])<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-l);
	}
	printf("%d\n",ans);
}
