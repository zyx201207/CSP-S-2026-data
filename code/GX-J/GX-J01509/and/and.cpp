#include<bits/stdc++.h>
using namespace std;
long long arr[1000005],n,m,arr1[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			arr1[i]=arr[i]&arr[j];
		}
	}
	sort(arr1+1,arr1+1+n,greater<long long>());
	cout<<arr1[1];
	return 0;
}
