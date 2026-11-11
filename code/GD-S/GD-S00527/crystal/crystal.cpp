#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre,co,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	pre=1;
	for(int i=1;i<=n;++i){
		co+=1ll*(i-pre)*(a[i]-a[i-1]);
		while(co>m){
			co-=(a[i]-a[pre]),pre++;
		}
		ans=max(ans,i-pre+1);
	}
	cout<<ans;
	return 0;
}

