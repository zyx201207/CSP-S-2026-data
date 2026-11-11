#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10;
int arr[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,greater<int>());
	m-=1;
	int xb=1;
	for(int i=1;i<=m;i++){
		for(int j=xb;j<=n;j++){
			dp[j]=arr[j] & arr[j-1];
		}
		for(int j=xb;j<=n;j++){
			arr[j]=dp[j];
		}
		xb++;
	}
	sort(arr+1,arr+n+1,greater<int>());
	cout<<arr[1];
	return 0;
}
