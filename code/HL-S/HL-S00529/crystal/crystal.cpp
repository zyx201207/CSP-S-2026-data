#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+9;
int n,ans;
ll a[N],sum[N],cnt,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]-a[i-1];
		//cout<<sum[i]<<" ";
	}
	//cout<<endl;
	ans=1;
	for(int l=1,r=2;r<=n;r++){
		while(cnt+sum[r]*(r-l)>m){
			cnt-=(a[r-1]-a[l++]);
		}
		cnt+=sum[r]*(r-l);
		//cout<<a[r]<<" "<<l<<" "<<r<<endl;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}