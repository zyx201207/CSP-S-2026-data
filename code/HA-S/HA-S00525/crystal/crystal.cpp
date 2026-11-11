#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cf[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		ll cnt=0,sum=0;
		for(int j=i;sum<=m&&j<=n;j++){
			sum+=cf[j]*(++cnt);
		}ans=max(ans,cnt);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
