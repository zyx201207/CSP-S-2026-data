#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin >> n >> m;
	int arr[200010];
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n);
	int ans=arr[n];
	for(int i=n;i>=n-m+1;i--){
		ans=ans&arr[i];
	}
	cout << ans;
	
	
	return 0;
}
