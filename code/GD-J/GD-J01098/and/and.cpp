#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[100000];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=2047;
	if(m==1){
		cout<<a[n];
	}else if(m==n){
		for(int i=1;i<=n;i++){
			ans=a[i]&ans;
		}	
		cout<<ans;
	}else{
		for(int i=n;i>n-m;i--){
			ans=a[i]&ans;
		}	
		cout<<ans;
	}
	return 0;
	
} 
