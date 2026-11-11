#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200001],ans; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1){
    	ans=-1e9;
		for(int i=1;i<=n;i++){
    		ans=max(ans,a[i]);
	    }
	    cout<<ans;
	    return 0;
	}
    if(k==n){
    	ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		} 
		cout<<ans;
		return 0;
	}
	if(k==2){
		long long x,y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					x=a[i],y=a[j];
					x&=y;
					ans=max(ans,x);
				}
			}
		}
		cout<<ans;
		return 0; 
	}
}

