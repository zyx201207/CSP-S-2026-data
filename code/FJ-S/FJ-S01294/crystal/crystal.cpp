#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001];
int cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	int flag=n,sum=0,ans=0;
	a[n+1]=a[n];
	for(int i=n;i>=1;i--){
		sum-=(i-flag+1)*(a[i+1]-a[i]);
		while(sum+a[i]-a[flag-1]<=m&&flag>=1){
			sum+=a[i]-a[flag-1];
			flag--;
		}
		ans=max(ans,i-flag+1);
	}
	printf("%lld",ans);
}
