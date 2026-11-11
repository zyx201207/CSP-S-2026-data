#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll ar[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,ar[i]&ar[j]);	
	    	}	
		}
		cout<<ans;
	}
	else if(m==1){
		cout<<ar[n];
	}
	else if(m==n){
		ans=ar[n];
		for(int i=1;i<=n;i++){
			ans=ans&ar[i];
		}
		cout<<ans;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;j<=n;j++){
					ans=max(ans,ar[i]&ar[j]&ar[k]);
				}
					
	    	}	
		}
		cout<<ans;
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;j<=n;j++){
					for(int l=k+1;l<=n;l++){
						ans=max(ans,ar[i]&ar[j]&ar[k]&ar[l]);
					}
					
				}
					
	    	}	
		}
		cout<<ans;
	}
	
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;j<=n;j++){
					for(int l=k+1;l<=n;l++){
						for(int h=k+1;h<=n;h++){
							ans=max(ans,ar[i]&ar[j]&ar[k]&ar[l]&ar[h]);
						}
					}
				}
					
	    	}	
		}
		cout<<ans;
	}
	else{
		ans=ar[n];
		for(int i=1;i<=m;i++){
			ans&=ar[n-i+1];
		}
		cout<<ans;
	}
	return 0;
}
