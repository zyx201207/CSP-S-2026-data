#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;cin>>n>>m;
	long long a[n];
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				int b=a[i]&a[j];
				ans=max(ans,b);
			}
		}
		cout<<ans;
	}
	else if(m==3){
		int ans=0;
		for(int i=1;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				for(int k=j+1;k<=n;++k){
					int b=a[i]&a[j]&a[k];
					ans=max(ans,b);
				}
				
			}
		}
		cout<<ans;
	}
	else if(m==4){
		int ans=0;
		for(int i=1;i<n-2;++i){
			for(int j=i+1;j<n-1;++j){
				for(int k=j+1;k<n;++k){
					for(int q=k+1;q<=n;++q){
						int b=a[i]&a[j]&a[k]&a[q];
						ans=max(ans,b);
					}
					
				}
				
			}
		}
		cout<<ans;
	}
	else if(m==5){
		int ans=0;
		for(int i=1;i<n-3;++i){
			for(int j=i+1;j<n-2;++j){
				for(int k=j+1;k<n-1;++k){
					for(int q=k+1;q<n;++q){
						for(int w=q+1;w<=n;++w){
							int b=a[i]&a[j]&a[k]&a[q]&a[w];
							ans=max(ans,b);
						}
						
					}
					
				}
				
			}
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	
	return 0;
}
