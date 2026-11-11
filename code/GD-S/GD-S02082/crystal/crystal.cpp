#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int sum[N];
int n,m;
bool cmp(int cm,int cp){
	return cm<cp;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int ans=0;
	int j=1;
	for(int i=1;i<=n;i++){
		while(sum[i]-sum[j-1]-(a[i]-a[j-1])*(j-1)>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld\n",ans);
	return 0;
}
