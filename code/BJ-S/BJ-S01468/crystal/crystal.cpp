#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[5*114514];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum = 0,l = 1,ans = 0,len;
	for(int r = 1;r<=n;r++){
		len = r-l+1;
		sum += (len-1)*(a[r]-a[r-1]);
		while(l <= r&&sum > m){
			sum -=(a[r]-a[l]);
			l++;
		}
		len = r-l+1;
		//cout<<l<<' '<<r<<' '<<sum<<'\n';
		ans = max(ans,len);
	}
	cout<<ans;
	return 0;
}
