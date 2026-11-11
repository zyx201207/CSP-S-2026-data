#include<bits/stdc++.h>
using namespace std;
int m,n;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=a[1];
	if(m==n){	
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	if(m==1){
		for(int i=2;i<=n;i++)ans=max(ans,a[i]);
	}
	if(m==2){
	    ans=INT_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
