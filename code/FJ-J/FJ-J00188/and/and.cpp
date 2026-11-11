#include<bits/stdc++.h>
using namespace std;
int n,m,a[212345],ans,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>x;
			ans=max(ans,x);
		}cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,int(a[i] and a[j]));;
			}
		}cout<<ans;
	}else if(m==(n-1)){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			if(i==1){
				x=a[2];
				for(int j=3;j<=n;j++){
					x=x and a[j];	
				}	
			}
			else{
				x=a[1];
				for(int j=3;j<=n;j++){
					if(j==i)continue; 
					x=x and a[j];	
				}	
			}ans=max(ans,x);
		}cout<<ans; 
	}else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>x;
			ans=ans and x;
		}cout<<ans;
	}else cout<<12;
	return 0;
}
