#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,cnt,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll sum=0;cnt=0;
		for(int j=i;j>0;j--){
			if(sum+(a[i]-a[j])<=m)sum+=a[i]-a[j],cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}
