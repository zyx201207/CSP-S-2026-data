#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],ma=-1;
	cin>>n>>m;
	bool b[n][31]={},f[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(long long i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long maxx=-1;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	
} 
