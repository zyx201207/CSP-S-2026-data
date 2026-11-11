#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=500005;
int n,m,a[N];
inline void ckmax(int& x,int y){x=max(x,y);}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int sum=0,cur=1,ans=1;
	rep(i,2,n){
		sum+=(i-cur)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[cur],cur++;
		ckmax(ans,i-cur+1);
	}
	printf("%lld\n",ans);
	return 0;
}
