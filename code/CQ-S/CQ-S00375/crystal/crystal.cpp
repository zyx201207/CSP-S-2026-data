#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,now,ans,a[500010],sum;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m,now=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(now+1<=n&&sum+(now-i+1)*(a[now+1]-a[now])<=m){
			sum+=(now-i+1)*(a[now+1]-a[now]); 
			now++;
		}
		ans=max(ans,now-i+1);
		sum-=a[now]-a[i];
		if(now==i)now++;
	}
	cout<<ans;
	return 0;
}
/*
 
*/
