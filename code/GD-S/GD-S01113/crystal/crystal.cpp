#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long minn;
long long sum=0,ans=1,ma_ans;
int l=1,r=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		minn=min(a[i],minn);
	}
	for(int i=1;i<=n;i++) a[i]-=minn;
	sort(a+1,a+n+1);
	while(r<n){
		if((r+1-l)*(a[r+1]-a[r])+sum<=m){
			sum+=(r+1-l)*(a[r+1]-a[r]);
			r++;
			ans++;
		}
		else{
			sum-=a[r]-a[l];
			l++;
			ans--;
		}
		ma_ans=max(ma_ans,ans);
	}
	printf("%lld",ma_ans);
	return 0;
}
