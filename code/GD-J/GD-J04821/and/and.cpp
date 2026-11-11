#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}else if(m==1){
		stable_sort(a+1,a+n+1);
		cout<<a[n];
	}else{
		stable_sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>=n-m;i--){
			ans=ans&a[i];
		}
	}
	
	cout<<ans;
} 
