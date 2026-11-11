#include <bits/stdc++.h>
using namespace std;
const int N=100010;
long long n,l,r;
long long arr[N],arr1[N];
char crr[N],crr1[N];
long long ans;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>crr[i];
	}
	
	for(int i=1;r-l>1;i++){
		if(crr[l]!=crr[r]){
			if(arr[l]>arr[r]){
				ans+=arr[l]-arr[r];
				arr[l]-=arr[r];
				r-=1;
			}else if(arr[l]<arr[r]){
				ans+=arr[r]-arr[l];
				
				arr[r]-=arr[r]-arr[l];
				l+=1;
			}else if(arr[l]==arr[r]){
				ans+=arr[l];
				l+=1;r-=1;
			}		
		}
	}
	if(crr[l]==crr[r]){
		cout<<ans;
		return 0;
	}
	else{
		ans+=min(arr[l],arr[r]);
		cout<<ans;
	}
	
	return 0;
}
