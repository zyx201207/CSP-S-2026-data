#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans,num,l;
	ans = 1;
	num = 0;
	l = 1;
	for(int i = 2;i<=n;i++){
		num = num+(i-l)*(a[i]-a[i-1]);
		while(num>m){
			num = num-(a[i]-a[l++]);
		}
		ans = max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}


