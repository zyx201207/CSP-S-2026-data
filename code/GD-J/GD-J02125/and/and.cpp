#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,ans;cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr+0,arr+n);
	ans=arr[n-1];
	for(int i=1;i<=m;i++){
		ans=ans&arr[n-i];
	}
	cout<<ans;
	return 0;
}
