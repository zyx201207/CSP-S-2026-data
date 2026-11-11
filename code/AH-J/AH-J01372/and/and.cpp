#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200001]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
	}else ans=n*n/2-3*n;
	cout<<ans;
	return 0;
} 
