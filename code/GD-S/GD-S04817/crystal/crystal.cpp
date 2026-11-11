#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, sum[500005], a[500005];
bool cmp(int x, int y){
	return x<y;
}
int check(int l, int r){
	int w=sum[r]-sum[l-1]-(l-1)*(a[r]-a[l-1]);
	if(w<=m)return 1;
	return 0; 
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout << sum[i] << " ";
	}
//	cout << endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1, r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid, i)){
				ans=max(ans, i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
