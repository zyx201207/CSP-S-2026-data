#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
	}else if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==n-1){
		long long ans=a[1];
		for(int i=2;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else{
		cout<<a[n-m];
	}
}
