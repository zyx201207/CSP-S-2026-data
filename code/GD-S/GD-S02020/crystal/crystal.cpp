#include <bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
int n,cnt,ans;
ll a[N],m,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	cnt=1;
	for(int l=1,r=1;r<=n;l++){
		r=max(r,l);
		cnt=r-l+1;
		while(r<n&&(a[r+1]-a[r])*cnt+k<=m){
			k+=(a[r+1]-a[r])*cnt;
			cnt++;
			r++;
		}
		ans=max(ans,r-l+1);
		k-=a[r]-a[l];
		cnt--;
	}
	printf("%d",ans);
	return 0;
}
