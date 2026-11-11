#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int ans=0;
	cin>>n>>m;
	long long a[n+1],b[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(b[i]-b[j-1]+m>=a[i]*(i-j+1)) ans=max(ans,i-j+1);
			else break;
		}
		if(ans==n){
			cout<<n;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
