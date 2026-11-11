//GZ-J00269 凯里学院附属中学 包煜森 
#include<bits/stdc++.h>
using namespace std;
int a[200005],m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(n==m){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=0,k=a[0];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					k=k&a[j];
				}
			}
			ans=max(ans,k);
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 

