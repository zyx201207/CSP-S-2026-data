#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int ma=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		 
			
	 		 
			if(ma<a[i]){
				ma=a[i];
			}
			                                                                                                                                                                                                   
		
		}
		cout<<ma;
	}
	if(m==n){
		cin>>a[1];int ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			
			ans=ans&a[i];		
		}
		cout<<ans;
		
	}
	if(m==2){		
		for(int i=1;i<=n;i++){
			cin>>a[i];			
		}
		int ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ans=(a[i]&a[j]);
				if(ma<ans){
					ma=ans;
					
				}
			}
		} 
		cout<<ma;
	}
	return 0;

}
