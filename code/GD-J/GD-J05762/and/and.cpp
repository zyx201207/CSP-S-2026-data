#include<iostream>
#include<cmath>
using namespace std;
int n,m,a[10000006];
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
	}	
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=(ans&a[i]);
		}
	}
	cout<<ans;
}
