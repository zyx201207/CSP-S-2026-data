//GZ-S00334 华东师范大学附属贵阳学校 向耕立
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N=1e6+10;
ll n,m,a[MAX_N],sum[MAX_N];
ll num=1,tail=1,pr,ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	while(num<=n){
		pr=(num-tail)*a[num];
		while(pr-(sum[num-1]-sum[tail-1])>m&&tail<num){
			tail++;
			pr=(num-tail)*a[num];
		}
		ans=max(ans,num-tail+1);
		num++;
	}
	cout<<ans;
	return 0;
}