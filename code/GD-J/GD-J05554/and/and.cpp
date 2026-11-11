#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
 	freopen("and.out", "w", stdout);
 	int n,m,a[200005];cin>>n>>m;
 	for(int i=1;i<=n;i++){cin>>a[i];}
 	
 	
 	if(m==n){
 		int x=a[1];
 		for(int i=2;i<=n;i++){
 			x=x & a[i];
	 	}
	 	cout<<x;
	 	return 0;}
	 	
	 	
	if(m==n-1){
		int ans;
		for(int i=1;i<=n;i++){
			int x=a[i];
			for(int j=1;j<=n;j++){
				if(j!=i){
					x=x & a[j];
				}
			}
			ans=max(ans,x);
		}
		cout<<ans;
		return 0;
	}
	
	
	if(m==1){
		int x=0;
		for(int i=1;i<=n;i++){
			x=max(x,a[i]);
		}
		cout<<x;
		return 0;
	}
	
	
	
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					int x= a[i] & a[j];
					ans=max(ans,x);
				}
			}
		}
		cout<<ans;
	}
	
}
