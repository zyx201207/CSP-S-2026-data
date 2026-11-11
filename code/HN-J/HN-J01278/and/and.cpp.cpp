#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-111;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
	}
	if(m==2){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			ans=max(ans,a[i]&a[j]);
		}
	}
	}
	if(m==3){
	for(int q=0;q<n;q++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j||i==q||j==q) continue;
				ans=max(ans,a[i]&a[j]&a[q]);
			}
		}
	}
	}
	cout<<ans;
	return 0;
} 
