#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int val=0,j=1,ans=0;
	for(int i=1;i<=n;i++){
		val+=(i-j)*(a[i]-a[i-1]);
		while(val>m){
			val-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
