#include<bits/stdc++.h>
using namespace std;
long long m,n,ans,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==n){
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}else{
		ans=a[n]&a[n-m+1];	
	}
	cout<<ans;
	return 0;
}
