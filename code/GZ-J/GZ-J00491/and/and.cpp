//GZ-J00491 遵义市第十九中学 陈昱昊 
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long c = 0;
long long arr[10000004];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);


	cin>>n>>m;

	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	if(n == 1){
		cout<<arr[1];
		return 0;
	}
	
	sort(arr+1,arr+n+1);
	for(int i = n;i>=m+1;i--){
		if(i == n){
			c = arr[i]&arr[i-1];
		}else{
			c = c&arr[i-1];
		}
	}
	cout<<c;
}
