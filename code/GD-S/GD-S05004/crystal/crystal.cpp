#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;
const int MAXN = 5e5 + 10;

int n,ans=0;
ll m;
ll a[MAXN],s[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	FL(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	FL(i,1,n) s[i]=s[i-1]+a[i];
	FL(i,1,n){
		int l=1,r=i,ps=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			//[mid,i-1]
			if(1ll*(i-mid)*a[i]-(s[i-1]-s[mid-1])<=m) ps=mid,r=mid-1;
			else l=mid+1;
		}
		assert(ps!=-1);
		ans=max(ans,i-ps+1);
	}
	printf("%d\n",ans);
}