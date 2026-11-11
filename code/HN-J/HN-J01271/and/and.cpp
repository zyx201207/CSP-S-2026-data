#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<0;
		return 0;
	}else {
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=a[i]and a[j];
				ans=max(ans,sum);
			}
		}
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i!=n){
				int sum=i+1;
				for(int j=1;j<=n;j++){
					if(i!=j&&j!=i+1){
						sum= sum and a[j]; 
					}
					ans=max(ans,sum);
				}
			}
			else{
				int sum=i-1;
				for(int j=1;j<=n;j++){
					if(i!=j&&j!=i-1){
						sum= sum and a[j]; 
					}
					ans=max(ans,sum);
				}
			} 
			
		}
	}cout<<ans;
	return 0;
} 
