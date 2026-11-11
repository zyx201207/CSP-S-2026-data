#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int arr[200005];
char brr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>brr[i];
	}
	int l=1,r=n;
	while(l<r){
		if(brr[l]!=brr[r]){
			if(arr[l]>arr[r]){
				ans+=arr[r];
				arr[l]-=arr[r];
				r--;
			}
			else if(arr[l]<arr[r]){
				ans+=arr[l];
				arr[r]-=arr[l];
				l++;
			}
			else{
				ans+=arr[l];
				l++;
				r--;
			}
		}
		else{
			if(arr[l]>arr[r]){
				arr[l]-=arr[r];
				r--;
			}
			else if(arr[l]<arr[r]){
				arr[r]-=arr[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
