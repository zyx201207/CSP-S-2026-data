#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=-1;
	cin >> n >> m;
	vector<int> a(n+1);
	bool flg=true;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a.begin()+1,a.end());
	int gc=a[2]-a[1];
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=gc)flg=false;
	if(flg){
		int cost=0;
		int cnt=1;
		for(int i=1;i<n;i++){
			cost+=gc*i;
			if(cost>m)break;
			cnt++;
		}
		cout << cnt;
		//cout << "dc";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		int cost=0;
		for(int j=i-1;j>=1;j--){
			cost+=a[i]-a[j];
			if(cost>m)break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout << ans;
    return 0;
}
