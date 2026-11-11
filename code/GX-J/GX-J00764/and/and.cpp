#include<bits/stdc++.h>
using namespace std;
int n,m,a[1919810],ans=-114514;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
		cin >> a[i];
    }	
    if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=(ans & a[i]);
	    }	
	    cout << ans;
	    return 0;
    }	
    else if(m==2){
		for(int l=0;l<n-1;l++){
		    for(int r=l+1;r<n;r++){
			    int d=(a[l] & a[r]);
			    if(d>ans){
				     ans=d;
		        }	
	        }	
        }	
        cout << ans;
        return 0;
    }	
    else if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
	    }	
	    cout << ans;
	    return 0;
    }		
    return 0;
}
