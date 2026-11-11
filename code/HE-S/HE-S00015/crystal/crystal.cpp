#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int n,m,a[N],sum[N];
int ra[5005],ans=-1e9;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool flag=true;
	bool fff=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=false;
		}
	}
	if(flag){
		int sum=0;
		int cnt=1;
		for(int i=1;i<=n;i++){
			sum+=i;
			cnt++;
			if(ans>m){
				sum-=i;
				cnt--;
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ra[i]=a[i];
	}
	sort(ra+1,ra+n+1);
	for(int i=1;i<=n;i++){
		int cnt=1;
		int sm=m;
		for(int p=i-1;p>=1;p--){
			if(sm>=a[i]-a[p]){
				sm-=(a[i]-a[p]);
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
