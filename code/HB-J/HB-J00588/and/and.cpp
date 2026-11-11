#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}	
	}
	cout<<ans;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
