#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n-1==m){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,ans&a[i]);
		}
		cout<<maxx;
	}else if(n>2000){
		sort(a+1,a+1+n);
		long long ans=a[n];
		for(int i=1;i<=m-1;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else{
		if(n==m){
			long long sum=a[1];  
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}
			cout<<sum; 
		}else if(m==1){
			long long sum=0;  
			for(int i=1;i<=n;i++){
				sum=max(sum,a[i]);
			}
			cout<<sum; 
		}else if(m==2){
			long long sum=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					sum=max(sum,a[i]&a[j]);	
				}	
			}
			cout<<sum;
		}
	}
	return 0;
}
