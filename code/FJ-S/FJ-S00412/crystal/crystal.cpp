#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+5;
int n,m,res=0,a[maxn],d[maxn];
bool flag = true;

bool check(int x){
	int ans = m+1;
	if(flag == true){
		for(int i=1;i<=n;i++){
			if(i>=x){
				int sum = d[2]*x*(x-1)/2;
				ans = min(sum,ans);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){//以a[i]为最大值 
			int sum = 0;
			if(i>=x){
				for(int j=i-1;j>=i-x+1;j--){
					sum+=(a[i]-a[j]);
				}
				ans = min(ans,sum);
			}
		}
	}

	if(ans <= m) {		
//		cout << x << " " << ans << endl;
		return true;
	}
	else return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		d[i] = a[i]-a[i-1];
		if(i > 2) if(d[i] != d[i-1]) flag = false;
	}
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			res = max(res,mid);
			l = mid+1;
//			cout << l << " " << r << endl;
		}
		else{
			r = mid-1;
		}
	}
	cout << res;
	return 0;
} 
