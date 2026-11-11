#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000001],ans,q,w; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				q=a[i]&a[j];
				ans=max(ans,q);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			w=a[1];
			for(int j=1;j<=n;j++){
				if(i!=j){
					w=w&a[j];
				}
			}
			ans=max(ans,w);
		}
		cout<<ans;
		return 0;
	}
	return 0; 
} 
