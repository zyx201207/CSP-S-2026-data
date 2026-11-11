#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int p=1,ans=1;
	ll cnt=0ll;
	for(int i=1;i<=n;i++){
		while(cnt>m&&p<i) cnt-=(a[i]-a[p]),p++;
		ans=max(ans,i-p+1);
		cnt+=1ll*(i-p+1ll)*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4

*/
