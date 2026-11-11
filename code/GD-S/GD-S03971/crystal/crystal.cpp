#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<':'<<(x)<<endl;
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N],now;
int l=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int r=1;r<=n;r++){
		now+=(a[r]-a[r-1])*(r-l);
		while(l<=r&&now>m)now-=(a[r]-a[l++]);
//		debug(now);debug(l)
		ans=max(ans,r-l+1);
	}printf("%d",ans);
} 
/*
5 5
1 2 4 9 8
*/
