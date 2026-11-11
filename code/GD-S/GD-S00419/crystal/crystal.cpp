#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int r=1;
	for(int i=1;i<=n;i++){
		ll len=r-i;sum-=a[r-1]-a[i-1];
		while(r<=n&&sum+(a[r]-a[r-1])*len<=m)sum+=(a[r]-a[r-1])*len,len++,r++;
		ans=max(ans,len);
	}
	printf("%lld",ans);
	
	return 0;
} 
