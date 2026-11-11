#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,INF=0x3f3f3f3f;
int n,l,r,now=0,ans=0;
ll m,a[N],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	now=l=r=1;
	while(r<=n){
		while(sum<=m&&r<=n){
			ans=max(ans,now);
			sum+=(a[r+1]-a[r])*now;
			now++,r++;
		}
		if(r>n) break;
		while(l<=r&&sum>m){
			sum-=a[r]-a[l];
			l++,now--;
		}
	}
	printf("%d\n",ans);
	return 0;
}

