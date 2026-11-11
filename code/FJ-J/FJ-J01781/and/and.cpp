#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

int a[1000100];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int p=a[i]&a[j];ans=max(p,ans);
			}
			
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int p=a[i]&a[j]&a[k];ans=max(p,ans);
				}
				
			}
			
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
