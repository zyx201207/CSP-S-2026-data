#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum,b,ans;
	int a[n];
	cin>>n>>m;
	for(int i = 0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int j = 0;j<=n-1;j++){
		sum = a[j] / 2;
		if(sum != 0){
			b = sum%2;
			a[j] = b;
		}
	}
	for(int j = n-1; j>=0;j--){
		ans = a[j] & a[j-1];
	}
	cout<<ans;
	
} 
