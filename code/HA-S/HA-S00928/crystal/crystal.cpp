#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a,sum;
int arr[500005];
int b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=1;i<=n;i++){
		a=0;
		sum=0;
		for(int j=i;j>=1;j--){
			sum+=arr[i]-arr[j];
			if(arr[j]<=arr[i]&&sum<=m){
				a++;
			}
		}
		ans=max(a,ans);
	}
	cout<<ans;
	return 0;
}
