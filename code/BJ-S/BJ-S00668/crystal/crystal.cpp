#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500000;
int n,m,sum,ans,l=1;
int a[MAXN+10];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);//(i-1)-l+1
		while(sum>m && l<i){
			sum-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
