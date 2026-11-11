#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 5,INF = 1e9;
int n;
long long a[N],pr[N],m;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) pr[i] = pr[i - 1] + a[i];
	int ans = 1;
	for (int i = 2;i <= n;i++){
		int l = 1,r = i;
		//cout<<"i = "<<i<<endl;
		while(l < r){
			int mid = l + r >> 1;
			//cout<<l<<" "<<r<<" "<<mid<<" "<<endl;
			long long pos = a[i] * (i - mid + 1) - (pr[i] - pr[mid - 1]);
			//cout<<a[i] * (i - mid + 1)<<" "<<pr[i] - pr[mid] - a[i]<<" "<<pos<<endl;
			//cout<<pr[i]<<" "<<pr[mid]<<endl;
			if (pos <= m) r = mid;
			else l = mid + 1;
		}
		//cout<<endl;
		ans = max(ans,i - l + 1);
	}
	cout<<ans<<endl;
	/*
	while(l <= r){
		long long mid = l + r >> 1;
		int pos = lower_bound(a + 1,a + n + 1,mid) - a + 1;
		if (mid * pos - pre[pos] <= m) 
	}
	*/
}
