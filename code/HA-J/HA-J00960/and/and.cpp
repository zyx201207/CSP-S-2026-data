#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			ans=max(ans,a[i]^a[j]);
		}
	}
	}
	 if(m==3){
	for(int i=1;i<=n;i++){
		for(int j=2;j<n;j++){
			for(int k=3;k<=n;k++){
				ans=max(ans,(a[i]^a[j]^a[k]));
			}
			
		}
	}
	}
	 if(m==4){
	for(int i=1;i<=n;i++){
		for(int j=2;j<n;j++){
			for(int k=3;k<=n;k++){
				for(int p=4;p<=n;p++){
				ans=max(ans,(a[i]^a[j]^a[k]^a[p]));
			}

			}
		}
	}
	}
	 if(m==5){
	for(int i=1;i<=n;i++){
		for(int j=2;j<n;j++){
			for(int k=3;k<=n;k++){
				for(int p=4;p<=n;p++){
				for(int x=5;x<=n;x++){
					ans=max(ans,a[i]^a[j]^a[k]^a[p]^a[x]);
				}
			}

			}
		}
	}
	}
	
	
	cout<<ans;
	return 0;
}
