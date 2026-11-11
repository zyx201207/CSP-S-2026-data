#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],maxa,ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout << maxa;
		return 0;
	}
	maxa=0;
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,a[i]&a[j]);
			}
		}
		cout << maxa;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans=ans&a[i];
	}
	cout << ans;
	return 0;
}
