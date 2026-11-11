#include <bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
    }
    int l=1;
    int r=n;
    long long cntsum=0;
    while(l<=r){
    	if(r-l==1 && (a[l]==0||a[r]==0)){
    		break;
        }
	    if(c[l]==c[r]){
		    if(a[l]>a[r]){
		    	a[l]-=a[r];
		    	r--;
		    }else{
		    	if(a[l]==a[r]){
		    		l++;
		    		r--;
		        }else{
		        	a[r]-=a[l];
		        	l++;
		        }
		    }
	    }else{
	    	cntsum+=min(a[l],a[r]);
	        if(a[l]>a[r]){
		    	a[l]-=a[r];
		    	r--;
		    }else{
		    	a[r]-=a[l];
		    	if(a[r]==0){
		    		l++;
		    		r--;
		        }else{
		        	l++;
		        }
		    }	
	    }
    }
    cout<<cntsum;
	return 0;
}
