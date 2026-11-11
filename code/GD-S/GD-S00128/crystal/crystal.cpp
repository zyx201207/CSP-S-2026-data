#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[1000005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n,m,ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++){
		int tmp=m,cnt=0;
		for (int j=i-1;j>=1;j--){
			if (tmp==0)break;
			if (a[i]-a[j]<=tmp){
				tmp-=(a[i]-a[j]);
			}else break;
			cnt++;
		}
		int cnt2=0;
		for (int j=i;a[j+1]==a[i];j++) cnt2++;
		ans=max(ans,cnt+cnt2+1);
	}
	cout<<ans;
	return 0;
}
