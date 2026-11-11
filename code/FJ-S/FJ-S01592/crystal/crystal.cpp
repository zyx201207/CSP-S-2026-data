#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,m,cnt,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	ans=1;
	for(int i=2;i<=n;i++){
		cnt+=(i-l)*(a[i]-a[i-1]);
		//cout<<i<<" "<<cnt<<"\n";
		while(cnt>m){
			cnt-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
//11 min
