#include<bits/stdc++.h>
using namespace std;
int a[200001];
int c1[200001];
int c2[200001];
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	c1[1]=a[1];
	c2[n]=a[n];
	for(int i=2;i<=n;i++){
		c1[i]=c1[i-1]&a[i];
	}
	for(int i=n-1;i>=1;i--){
		c2[i]=c2[i+1]&a[i];
	}
	int ans=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=c1[n];
	}else if(m==n-1){
		ans=max(c1[n-1],c2[2]);
		for(int i=2;i<n;i++){
			ans=max(ans,c1[i-1]&c2[i+1]);
		}
	}else if(n<=20){
		
	}else{
		
	}
	cout<<ans;
	return 0;
}
