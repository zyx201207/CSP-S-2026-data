#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=0,i=1;
	while(i<=n){
		ll zz=lower_bound(a+1,a+n+1,a[i])-a,cnt=0,k=a[i],flag=0;
		ll len=lower_bound(a+1,a+n+1,a[i]+1)-lower_bound(a+1,a+n+1,a[i]);
		i+=len;
		while(1){
			zz--;
			if(zz<1)break;
			cnt+=(k-a[zz]);
			if(cnt>m){
				flag=1;
				break;
			}
			len++;
		}
		if(!flag)len--;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
