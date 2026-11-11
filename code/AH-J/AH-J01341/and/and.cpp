#include <bits/stdc++.h>
using namespace std;
int n,m,a[20000005];
int mx=-1000000,h;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i],mx=max(mx,a[i]);

	if(m==1){
		cout << mx;
		return 0;
	}
	if(m==n){
		h=a[1];
		for(int i=2;i<=n;i++) h=h&a[i];
		cout << h;
		return 0;
	}
	if(m==2){
		int ans=-1000;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m==n-1){
		int ans1=-10000,ans2=-100000;
		ans1=a[1],ans2=a[2];
		for(int i=1;i<n;i++) ans1=ans1&a[i];
		for(int i=2;i<=n;i++) ans2=ans2&a[i];
		cout << max(ans1,ans2);
		return 0;
	}
	cout << 4;
	
	return 0;
}
