#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[500000],ans=0;
int main(){
		freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	} 
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((b[j]-b[i-1]+m)>=a[j]*(j-i+1)){
				ans=max(ans,j-i+1);
			}
	} 
	} 
	cout<<ans;
	return 0;
}
