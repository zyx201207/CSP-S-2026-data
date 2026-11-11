#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxx=max((a[i]&a[j]),maxx);
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		int ans=0;
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		int t=a[1];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) t+= (t & a[j]); 
			}
			ans=max(t,ans);
		}
		cout<<ans;
		return 0;
	}
	
}
