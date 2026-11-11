#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,l,r,ans=INT_MIN,ans1=INT_MIN,ans2=INT_MIN,a[511111];
bool check1(int x){
	int cnt=0,sum=0;
	for (int i=n;i>=1;i--){
		if (a[i]<=x){
			sum+=(x-a[i]);
			if (sum<=m){
				cnt++;
			}else{
				break;
			}
		}
	}
	if (cnt>ans1){
		ans1=cnt;
		return 1;
	}
	return 0;
}
bool check2(int x){
	int cnt=0,sum=0;
	for (int i=n;i>=1;i--){
		if (a[i]<=x){
			sum+=(x-a[i]);
			if (sum<=m){
				cnt++;
			}else{
				break;
			}
		}
	}
	if (cnt>ans2){
		ans2=cnt;
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if (n<=5000){
		for (int i=1;i<=n;i++){
			int cnt=0,sum=0;
			for (int j=i;j>=1;j--){
				sum+=a[i]-a[j];
				if (sum<=m){
					cnt++;
				}else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout << ans;
	}else{
		l=1,r=m;
		while (l<=r){
			int mid=(l+r)/2;
			if (check1(mid)){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		l=1,r=m;
		while (l<=r){
			int mid=(l+r)/2;
			if (check2(mid)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		cout << max(ans1,ans2);
	}
	return 0;
} 
