#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int m,n,a[2005];
	cin>>n>>m;
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>ans){
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		int ans;
		cin>>ans;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[i]&a[j])>ans&&(i!=j)){
					ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
	}
}
